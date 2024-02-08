class Solution{
public:
	vector<int> nextSmallerElement(vector<int> &arr, int n)
	{
	    vector<int>next(n);
	    stack<int>st;
	    for(int i=n-1;i>=0;i--){
	        while(!st.empty() && st.top()>=arr[i])
	            st.pop();
	        next[i]=st.empty()?-1:st.top();
	        st.push(arr[i]);
	    }
	    return next;
	}
};

/*
	You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
	Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
	If for any array element the next smaller element does not exist, you should print -1 for that array element.

	Input: 2  1 4  3
	output:1 -1 3 -1
	
	T.C : O(n)
	S.C : O(n)
*/
