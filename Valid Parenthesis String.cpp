class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st1,st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st1.push(i);
            else if(s[i]==')'){
                if(!st1.empty())
                    st1.pop();
                else if(!st2.empty())
                    st2.pop();
                else
                    return false;
            }
            else
                st2.push(i);
        }
        
        while(!st1.empty() && !st2.empty()){
            if(st1.top()<st2.top()){
                st1.pop();
                st2.pop();
            }
            else
                return false;
        }
        return st1.empty();
    }
};


//Code-2 S.C : O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int open=0,close=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='*')
                open++;
            else
                open--;
            if(open<0)
                return false;
        }
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*')
                close++;
            else
                close--;
            if(close<0)
                return false;
        }
        return true;
    }
};

/*
	Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
	The following rules define a valid string:
		.Any left parenthesis '(' must have a corresponding right parenthesis ')'.
		.Any right parenthesis ')' must have a corresponding left parenthesis '('.
		.Left parenthesis '(' must go before the corresponding right parenthesis ')'.
		.'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

	Example 1:
	Input: s = "()"
	Output: true
	
	Example 2:
	Input: s = "(*)"
	Output: true
	
	Example 3:
	Input: s = "(*))"
	Output: true
	
	T.C : O(n)
	S.C : O(n)
*/
