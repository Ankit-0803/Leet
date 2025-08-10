class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxxprofit=0;
        int currentprice=prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<currentprice){
                currentprice=prices[i];
            }
            int profit=prices[i]-currentprice;
            maxxprofit=max(maxxprofit, profit);

        }
        return maxxprofit;

        
    }
};