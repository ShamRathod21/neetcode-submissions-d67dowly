class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxSell(prices.begin(),prices.end());
        int n = prices.size();
        int i =0;
        if(n == 1)
         return 0;
                 maxSell[n-1] = prices[n-1];
       for(int i = n -2; i >= 0; i--) {
            maxSell[i] = max(prices[i],maxSell[i+1]);
        }
        int profit = 0;
        i =0;
        for(i; i< prices.size(); i++) {
            profit = max(profit,maxSell[i] - prices[i]);
        }
        return profit;
    }
};
