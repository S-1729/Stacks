class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string str;
        for(auto i:num){
            while(!st.empty() && k>0 && st.top()>i){
                st.pop();
                k--;
            }
            st.push(i);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        
        int i=0;
        while(i<str.size() && str[i]=='0')
            i++;
        
        if(i==str.size())
           return "0";
        return str.substr(i);
    }
};


//using string as stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        string str;
        for(auto i:num){
            while(!str.empty() && k>0 && str.back()>i){
                str.pop_back();
                k--;
            }
            str.push_back(i);
        }
        
        while(!str.empty() && k>0){
            str.pop_back();
            k--;
        }
        
        int i=0;
        while(i<str.size() && str[i]=='0')
            i++;
        
        if(i==str.size())
           return "0";
        return str.substr(i);
    }
};

/*
	Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
	
	Example 1:
	Input: num = "1432219", k = 3
	Output: "1219"
	Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
	
	Example 2:
	Input: num = "10200", k = 1
	Output: "200"
	Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
	
	Example 3:
	Input: num = "10", k = 2
	Output: "0"
	Explanation: Remove all the digits from the number and it is left with nothing which is 0.

	T.C : O(n)
	S.C : O(n)
*/
