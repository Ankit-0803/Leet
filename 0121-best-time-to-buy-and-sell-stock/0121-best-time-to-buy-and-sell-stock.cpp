class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0; i<prices.size(); i++){
            //update the minimum price if possible
            if(prices[i]<minPrice)
            minPrice=prices[i];
            else
            //if minimum price is not updated, update maxprofit
            maxProfit=max(maxProfit, prices[i]-minPrice);
        }return maxProfit;
        
    }
};