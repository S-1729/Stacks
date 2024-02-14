class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[st.top()]=='(' && s[i]==')'){
                st.pop();
                int len=st.empty()?i+1:i-st.top();
                ans=max(ans,len);
            }
            else
                st.push(i);
        }
        return ans;
    }
};


//Approach-2 without using stack
//T.C : O(2n)
//S.C : O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,open=0,close=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            if(close>open)
                open=0,close=0;
        }
        
        open=0,close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            if(open>close)
                open=0,close=0;
        }
        
        return ans;
    }
};

/*
	Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
	
	Example 1:
	Input: s = "(()"
	Output: 2
	Explanation: The longest valid parentheses substring is "()".
	
	Example 2:
	Input: s = ")()())"
	Output: 4
	Explanation: The longest valid parentheses substring is "()()".
	
	Example 3:
	Input: s = ""
	Output: 0
	
	T.C : O(n)
	S.C : O(n)
*/
