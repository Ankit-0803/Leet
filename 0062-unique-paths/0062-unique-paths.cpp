class Solution {
public:
    int paths(int m, int n, vector<vector<int>>& dp){
        //base case
        if(m==0 || m==0)return 1; //only one path possible for single row single column
        if(m<0 || n<0)return 0; //no paths possible
        if(dp[m][n]!=-1)return dp[m][n];
        //up or left
        int up=paths(m-1, n, dp);
        int left=paths(m, n-1, dp);
        //store and return the answer
        return dp[m][n]=up+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, dp);
        }
};