class Solution {
public:
    void dfs(vector<vector<char>>& grid, int rows, int cols){
        int m=grid.size();
        int n=grid[0].size();
        if(rows<0 || rows>=m || cols<0 || cols>=n || grid[rows][cols]=='0'){
            return;
        }
        grid[rows][cols]='0'; //mark current box 0 to avoid further confusion
        //move in all four directions and mark them 0
        dfs(grid, rows+1, cols);
        dfs(grid, rows-1, cols);
        dfs(grid, rows, cols+1);
        dfs(grid, rows, cols-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    count++; //increase count by 1
                    dfs(grid, i, j); //make all adjacent 1's included
                }
            }
        }
        return count;
    }
};