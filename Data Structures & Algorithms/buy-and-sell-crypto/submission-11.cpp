class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        vector<int> sell(prices.begin(),prices.end());
        int n = prices.size() - 1;
        for(int i = n - 1; i >= 0; i--) {
            cout << sell[i] << " " << sell[i+1] << endl;
            sell[i] = max(sell[i],sell[i+1]);
        }
        
        for(int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, sell[i]-prices[i]);
        }
        return maxProfit;
    }
};
