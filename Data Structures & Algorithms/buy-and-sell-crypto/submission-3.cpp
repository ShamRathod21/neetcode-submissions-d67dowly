class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxSell(n);
        maxSell[n-1] = prices[n-1];
        for(int i = n -2; i >= 0; i--) {
            maxSell[i] = max(prices[i],maxSell[i+1]);
        }
        int profit = 0;
        for(int i = 0; i < n; i++) {
            profit = max(profit, maxSell[i] - prices[i]);
        }
        return profit;
    }
};
