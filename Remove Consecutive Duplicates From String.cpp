class Solution{
public:
	string removeConsecutiveDuplicates(string str) 
	{
	    int n=str.size();
	    stack<char>st;
	    st.push(str[0]);
	    for(int i=1;i<n;i++){
	        if(str[i]!=st.top())
	        st.push(str[i]);
	    }
	    string ans;
	    while(!st.empty()){
	        ans=st.top()+ans;
	        st.pop();
	    }
	    return ans;
	}
};

/*
	You are given a string 'STR' consisting of lower and upper case characters. You need to remove the consecutive duplicates characters, and return the new string.
	Example :
	For a given string, "aaaAAbbcccbd"
	The new string formed after removing the consecutive duplicates characters will be, "aAbcbd".

	Sample Input :
	aabccba
	Sample Output :
	abcba
	
	T.C : O(n)
	S.C : O(n)
*/
