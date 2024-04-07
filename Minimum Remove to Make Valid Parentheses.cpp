class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str,ans;
        int open=0,close=0;
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            if(s[i]=='(')
                open++;
            if(s[i]==')')
                close++;
            if(close>open){
                close--;
                str.pop_back();
            }
        }
        
        open=0,close=0;
        for(int i=str.size()-1;i>=0;i--){
            ans.push_back(str[i]);
            if(str[i]=='(')
                open++;
            if(str[i]==')')
                close++;
            if(close<open){
                open--;
                ans.pop_back();
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};

/*
	Given a string s of '(' , ')' and lowercase English characters.
	Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
	Formally, a parentheses string is valid if and only if:
		.It is the empty string, contains only lowercase characters, or
		.It can be written as AB (A concatenated with B), where A and B are valid strings, or
		.It can be written as (A), where A is a valid string.

	Example 1:
	Input: s = "lee(t(c)o)de)"
	Output: "lee(t(c)o)de"
	Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
	
	Example 2:
	Input: s = "a)b(c)d"
	Output: "ab(c)d"
	
	Example 3:
	Input: s = "))(("
	Output: ""
	Explanation: An empty string is also valid.

	T.C : O(n)
	S.C : O(n)
*/
