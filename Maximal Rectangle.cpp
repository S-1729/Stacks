class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size(),area=0;
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i]) ){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                area=max(area,height*width);
            }
            st.push(i);
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea=0,n=matrix.size(),m=matrix[0].size();
        vector<int>v(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!='0')
                    v[j]=v[j]+1;
                else
                    v[j]=0;
            }
            maxarea=max(maxarea,largestRectangleArea(v));
        }
        return maxarea;
    }
};

/*
	Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
	
	Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
	Output: 6
	
	T.C : O(n*m)
	S.C : O(n)
*/

