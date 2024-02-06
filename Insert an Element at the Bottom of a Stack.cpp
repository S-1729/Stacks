class Solution{
public:
    void solve(stack<int>&st,int x)
    {
        if(st.empty()){
            st.push(x);
            return ;
        }
        int num=st.top();
        st.pop();
        solve(st,x);
        st.push(num);
    }
    
    stack<int> insertAtBottom(stack<int> St,int X){
        solve(St,X);
        return St;
    }
};

/*
	You are given a stack St of N integers and an element X. You have to insert X at the bottom of the given stack.
	
	Input:
	N = 5
	X = 2
	St = {4,3,2,1,8}
	Output:
	{2,4,3,2,1,8}
	
	T.C : O(n)
*/
