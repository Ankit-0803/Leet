class Solution {
public:
    void dfs(vector<vector<char>>& grid, int rows, int cols){
        int n=grid.size();
        int m=grid[0].size();
        //check bounds and skip water
        if(rows<0 || rows>=n || cols<0 || cols>=m ||grid[rows][cols]=='0')return;
        grid[rows][cols]='0'; //mark current land as water to avoid repeatation
        //now traverse in all four directions of current land
        dfs(grid, rows+1, cols);
        dfs(grid, rows-1, cols);
        dfs(grid, rows, cols+1);
        dfs(grid, rows, cols-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
           if(n==0)return 0;
        int m=grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;          //new island found
                    dfs(grid, i, j); //mark all its part
                }
            }
        }return count;
    }
};