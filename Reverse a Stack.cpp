class Solution{
public:
    void insertAtBottom(stack<int>&St,int x){
        if(St.empty()){
        St.push(x);
        return ;
        }
        int num=St.top();
        St.pop();
        insertAtBottom(St,x);
        St.push(num);
    }
    
    void solve(stack<int>&St){
        if(St.empty())
        	return ;
        	
        int num=St.top();
        St.pop();
        solve(St);
        insertAtBottom(St,num);
    }
    
    void Reverse(stack<int> &St){
        solve(St);
    }
};

/*
	You are given a stack St. You have to reverse the stack using recursion.
	
	Input:
	St = {3,2,1,7,6}
	Output:
	{6,7,1,2,3}
	
	T.C : O(n*n)
*/
