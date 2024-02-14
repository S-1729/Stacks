//Leetcode
class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 
/*
	Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

	The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
	
	For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
	Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
	Implement the StockSpanner class:
	
	StockSpanner() Initializes the object of the class.
	int next(int price) Returns the span of the stock's price given that today's price is price.
	
	Input:
	["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
	[[], [100], [80], [60], [70], [60], [75], [85]]
	Output:
	[null, 1, 1, 1, 2, 1, 4, 6]
	
	Explanation:
	StockSpanner stockSpanner = new StockSpanner();
	stockSpanner.next(100); // return 1
	stockSpanner.next(80);  // return 1
	stockSpanner.next(60);  // return 1
	stockSpanner.next(70);  // return 2
	stockSpanner.next(60);  // return 1
	stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
	stockSpanner.next(85);  // return 6
	
	T.C : O(n)
	S.C : O(n)
*/



//GeeksforGeeks
class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && price[st.top()]<=price[i])
            st.pop();
            ans[i]=st.empty()?i+1:(i-st.top());
            st.push(i);
        }
        return ans;
    }
};

/*
	The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
	The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.
	For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

	Input: 
	N = 7, price[] = [100 80 60 70 60 75 85]
	Output:
	1 1 1 2 1 4 6
	
	T.C : O(n)
	S.C : O(n)
*/
