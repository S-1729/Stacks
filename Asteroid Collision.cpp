class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ele : asteroids){
            while(!st.empty() && ele<0 && st.top()>0){
                int sum=st.top()+ele;
                if(sum<0)
                    st.pop();
                else if(sum>0)
                    ele=0;
                else{
                    st.pop();
                    ele=0;
                }
            }
                
            if(ele!=0)
                st.push(ele);
        }
        
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};


//using vector as stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        for(auto ele : asteroids){
            while(!v.empty() && ele<0 && v.back()>0){
                int sum=v.back()+ele;
                if(sum<0)
                    v.pop_back();
                else if(sum>0)
                    ele=0;
                else{
                    v.pop_back();
                    ele=0;
                }
            }
                
            if(ele!=0)
                v.push_back(ele);
        }
        return v;
    }
};

/*
	We are given an array asteroids of integers representing asteroids in a row.
	For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
	Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

	Example 1:
	Input: asteroids = [5,10,-5]
	Output: [5,10]
	Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
	
	Example 2:
	Input: asteroids = [8,-8]
	Output: []
	Explanation: The 8 and -8 collide exploding each other.
	
	Example 3:
	Input: asteroids = [10,2,-5]
	Output: [10]
	Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

	T.C : O(n)
	S.C : O(n)
*/
	
