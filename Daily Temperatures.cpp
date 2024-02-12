class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>next(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
                st.pop();
            next[i]=st.empty()?0:st.top()-i;
            st.push(i);
        }
        return next;
    }
};

/*
	Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
	If there is no future day for which this is possible, keep answer[i] == 0 instead.
	
	Input: temperatures = [73,74,75,71,69,72,76,73]
	Output: [1,1,4,2,1,1,0,0]
	
	Input: temperatures = [30,40,50,60]
	Output: [1,1,1,0]
	
	T.C : O(n)
	S.C : O(n)
*/
