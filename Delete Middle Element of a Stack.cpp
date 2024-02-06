class Solution
{
    public:
    void solve(stack<int>&s, int i, int n)
    {
        if(i==n/2){
            s.pop();
            return ;
        }
        int x=s.top();
        s.pop();
        solve(s,i+1,n);
        s.push(x);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        solve(s,0,sizeOfStack);
    }
};

/*
	Given a stack, delete the middle element of the stack without using any additional data structure.
	Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.
	Note: The output shown by the compiler is the stack from top to bottom.

	Input: 
	Stack = {10, 20, 30, 40, 50}
	Output:
	ModifiedStack = {10, 20, 40, 50}
	
	Input: 
	Stack = {10 20 30 40}
	Output:
	ModifiedStack = {10 30 40}
	
	T.C : O(n)
*/
