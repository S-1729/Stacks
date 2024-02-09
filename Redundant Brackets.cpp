class Solution{
public:
	bool findRedundantBrackets(string &s)
	{
	    stack<char>st;
	    for(auto i:s){
	        if(i=='('||i=='+'||i=='-'||i=='*'||i=='/')
	            st.push(i);
	        else{
	            if(i==')'){
	                bool isRedundant=true;
	                while(st.top()!='('){
	                    isRedundant=false;
	                    st.pop();
	                }
	                if(isRedundant)
	                	return true;
	                st.pop();
	            }
	        }
	    }
	    return false;
	}
};

/*
	Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. 
	The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
	Note :
	A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.
	
	Sample Input 1 :
	(a+b)
	(a+c*b)+(c))
	
	Sample Output 1 :
	No
	Yes
	
	Explanation of Sample Input 1 :
	In the first test case, there are no redundant brackets. Hence, the output is “No”. 	
	In the second test case, the brackets around the alphabet ‘c’( index 8 and index 10) are redundant. Hence the output is “Yes”.
*/
