class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size(),area=0;
       stack<int>st;
       for(int i=0;i<=n;i++){
         while(!st.empty()&& (i==n || heights[st.top()]>heights[i])){
           int height=heights[st.top()];
           st.pop();
           int width=st.empty()?i:i-st.top()-1;
           area=max(area,height*width);
         }
         st.push(i);
       }
       return area;
    }
};

/*
	Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
	
	Input: heights = [2,1,5,6,2,3]
	Output: 10
	Explanation: The above is a histogram where width of each bar is 1.
	The largest rectangle is shown in the red area, which has an area = 10 units.
	
	T.C : O(n)
	S.C : O(n)
*/
