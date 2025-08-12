class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        //base case
        //starting cell
        if(i==0 && j==0)return grid[0][0];
        // out of bound
        if(i<0||j<0)return INT_MAX;
           if (dp[i][j] != -1) 
            return dp[i][j];
        int up=f(i-1, j, grid, dp);
        int left=f(i, j-1, grid, dp);
        int minPath=min(up,left);
        
        // If both are invalid (INT_MAX), return INT_MAX
        if (minPath == INT_MAX) 
            return dp[i][j] = INT_MAX;
        // Otherwise, include the current cell's value in the total
        return dp[i][j] = grid[i][j] + minPath;


    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1, m-1, grid, dp);
    }
};