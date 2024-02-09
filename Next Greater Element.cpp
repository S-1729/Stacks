class Solution{
public:
	vector<int> nextGreaterElement(vector<int>& arr, int n)
	{
		vector<int>next(n);
		stack<int>st;
		for(int i=n-1;i>=0;i--){
			while(!st.empty() && st.top()<=arr[i])
				st.pop();
			next[i]=st.empty()?-1:st.top();
			st.push(arr[i]);
		}
		return next;
	}
};

/*
	You are given an array 'a' of size 'n'.
	Print the Next Greater Element(NGE) for every element.
	The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.
	If no greater elements exist to the right of 'x', consider the next greater element as -1.
	
	Sample Input:
	5
	1 5 3 4 2
	
	Sample Output:
	5 -1 4 -1 -1

	T.C : O(n)
	S.C : O(n)
*/
