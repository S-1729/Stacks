class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(),num3=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<num3)
                return true;
            while(!st.empty() && nums[i]>st.top()){
                num3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

/*
	Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
	Return true if there is a 132 pattern in nums, otherwise, return false.

	i	< j  < k
	num1 num2 num3
	num1<num3<num2
	
	Example 1:
	Input: nums = [1,2,3,4]
	Output: false
	Explanation: There is no 132 pattern in the sequence.
	
	Example 2:
	Input: nums = [3,1,4,2]
	Output: true
	Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
	
	Example 3:
	Input: nums = [-1,3,2,0]
	Output: true
	Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
	
	T.C : O(n)
	S.C : O(n)
*/
	
