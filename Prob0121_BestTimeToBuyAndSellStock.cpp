class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = prices.size();
        int buyAtPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            buyAtPrice = min(buyAtPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
        }
        return maxProfit;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Code explained:
// We are using a bottom up approach to solve this problem. We are using two variables buyAtPrice and maxProfit to store the minimum price at which we can buy the stock and the maximum profit that we can make. We are initializing buyAtPrice to INT_MAX and maxProfit to 0. We are using a for loop to iterate through the prices array. For each price, we are updating the value of buyAtPrice to the minimum of buyAtPrice and prices[i]. We are also updating the value of maxProfit to the maximum of maxProfit and prices[i] - buyAtPrice. Finally we are returning the value of maxProfit which is the maximum profit that we can make.
// when we are at the ith day, we are calculating the profit that we can make by selling the stock on the ith day. We are updating the value of maxProfit to the maximum of maxProfit and prices[i] - buyAtPrice. We are also updating the value of buyAtPrice to the minimum of buyAtPrice and prices[i]. This way we are keeping track of the minimum price at which we can buy the stock and the maximum profit that we can make. Finally we are returning the value of maxProfit which is the maximum profit that we can make.