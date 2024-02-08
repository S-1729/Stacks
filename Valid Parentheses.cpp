class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp={ {')','('}, {']','['}, {'}','{'}};
        stack<char>st;
        for(auto i:s){
            if(i=='[' || i=='{' || i=='(')
                st.push(i);
            else{
                if(!st.empty() && st.top() == mp[i])
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};

/*
	Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

	An input string is valid if:
		1.Open brackets must be closed by the same type of brackets.
		2.Open brackets must be closed in the correct order.
		3.Every close bracket has a corresponding open bracket of the same type.
	
	Input: s = "()[]{}"
	Output: true
	
	Input: s = "(]"
	Output: false
	
	T.C : O(n)
	S.C : O(n)
*/
