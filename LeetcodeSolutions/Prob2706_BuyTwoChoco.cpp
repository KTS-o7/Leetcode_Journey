class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int sum = INT_MAX;
        int i  = 0,j =prices.size()-1;
        while(i<j)
        {
            if(prices[i]+prices[j]<sum)
            {
                sum=prices[i]+prices[j];
            }
            if(prices[i]<prices[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return (sum>money)?(money):(money-sum);
    }
};

// Time complexity: O(n)
// Space complexity: O(1)