class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            // If today's price is higher than yesterday's
            // we can take profit by buying yesterday & selling today
            if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
        
    }
};
// LeetCode’s “stock” problems are hypothetical.
// They give you the whole list of prices beforehand.
// The challenge is not forecasting, but finding the max possible profit if you had perfect knowledge of future prices.