class Solution {
public:
    string makeGood(string s) {
        string ans="";
        for(auto ch:s){
            int n=ans.size();
            if(n>0 && (ans[n-1]==ch+32 || ans[n-1]==ch-32))
                ans.pop_back();
            else
                ans.push_back(ch);
        }
        return ans;
    }
};

//Code-2 S.C : O(n)
class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && tolower(st.top())==tolower(ch) && ((islower(st.top()) && isupper(ch)) || (islower(ch) && isupper(st.top()))))
                st.pop();
            else
                st.push(ch);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

/*
	Given a string s of lower and upper case English letters.
	A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
		.0 <= i <= s.length - 2
		.s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
	To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
	Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
	Notice that an empty string is also good.

	Example 1:
	Input: s = "leEeetcode"
	Output: "leetcode"
	Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
	
	Example 2:
	Input: s = "abBAcC"
	Output: ""
	Explanation: We have many possible scenarios, and all lead to the same answer. For example:
	"abBAcC" --> "aAcC" --> "cC" --> ""
	"abBAcC" --> "abBA" --> "aA" --> ""
	
	Example 3:
	Input: s = "s"
	Output: "s"
	
	T.C : O(n)
*/
