class Solution {
public:
    int solve(int n, vector<int>&dp){
        //base case
        if(n==0 || n==1)return 1;
        //if already computed return from dp
        if(dp[n]!=-1)return dp[n];
        //take 1 step
        int take1=solve(n-1, dp);
        //take 2 step
        int take2=solve(n-2, dp);
        //store and return the result
        return dp[n]=take1+take2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};