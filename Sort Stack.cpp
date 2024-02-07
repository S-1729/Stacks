class{
  public:
		
	void insertAtCorrectPosition(stack<int>&st,int x)
	{
		if(st.empty() || x>=st.top()){
			st.push(x);
			return ;
		}
		int num=st.top();
		st.pop();
		insertAtCorrectPosition(st,x);
		st.push(num);
	}
	
	void sortStack(stack<int> &stack)
	{
		if(stack.empty())
		return ;
		int num=stack.top();
		stack.pop();
		sortStack(stack);
		insertAtCorrectPosition(stack,num);
	}
};

/*
	Given a stack, the task is to sort it such that the top of the stack has the greatest element.
	
	Input:
	Stack:  11 2 32 3 41
	Output: 41 32 11 3 2
	
	T.C : O(n*n)
*/
