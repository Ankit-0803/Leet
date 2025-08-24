class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int cp=prices[0];
            for(int i=1; i<n; i++){
            int profit=prices[i]-cp;
            maxprofit=max(maxprofit, profit);
            cp=min(cp, prices[i]);

        }
        return maxprofit;
        
    }
};