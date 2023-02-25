class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maximumProfit = 0, minStockVal = INT_MAX;
        int i = 0;
        while (i < n) {
            minStockVal = min(minStockVal, prices[i]);
            // whenever the price of current stock is greater then then the stock value which we bought then only we will sell the stock 
            if (prices[i] >= minStockVal)
                maximumProfit = max(maximumProfit, prices[i] - minStockVal);
            i++;
        }
        return maximumProfit;
    }
};