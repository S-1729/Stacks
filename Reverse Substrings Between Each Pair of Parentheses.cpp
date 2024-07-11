class Solution {
public:
    void Reverse(string &s,int i,int j){
        while(i<j){
            char c=s[i];
            s[i++]=s[j];
            s[j--]=c;
        }
    }
    
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                int x=st.top();
                st.pop();
                int y=i;
                Reverse(s,x,y);
            }
        }
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')')
                str.push_back(s[i]);
        }
        
        return str;
    }
};

//Code-2
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        vector<int>mp(n,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                int x=st.top();
                st.pop();
                mp[x]=i;
                mp[i]=x;
            }
        }
        
        string str;
        int d=1;
        for(int i=0;i<s.size();i+=d){
            if(s[i]=='(' || s[i]==')'){
                i=mp[i];
                d=d*-1;
            }
            else
                str.push_back(s[i]);
        }
        return str;
    }
};

/*
    You are given a string s that consists of lower case English letters and brackets. 
    Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.
  
    Example 1:
    Input: s = "(abcd)"
    Output: "dcba"
    
    Example 2:
    Input: s = "(u(love)i)"
    Output: "iloveu"
    Explanation: The substring "love" is reversed first, then the whole string is reversed.
    
    Example 3:
    Input: s = "(ed(et(oc))el)"
    Output: "leetcode"
    Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
     
    T.C : O(n*n)
    S.C : O(n)
*/
