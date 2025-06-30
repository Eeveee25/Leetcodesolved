class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];  // best price to buy so far
        int maxProfit = 0;         // best profit we can make
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];  // update best buy
            } else {
                int profit = prices[i] - minPrice;  // potential sell
                maxProfit = max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
};
