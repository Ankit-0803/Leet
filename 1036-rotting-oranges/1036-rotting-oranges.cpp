class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        int freshOranges = 0;   // Count of fresh oranges
        queue<pair<int, int>> q; // Queue to store coordinates of rotten oranges
        // Step 1: Initialize queue with all rotten oranges and count fresh ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j}); // Store rotten orange position
                } else if(grid[i][j] == 1) {
                    freshOranges++; // Count fresh oranges
                }
            }
        }
        // If no fresh oranges are present, return 0 (already rotten or empty grid)
        if(freshOranges == 0) return 0;
        // Direction vectors for moving in 4 possible directions (Right, Down, Left, Up)
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int minutes = 0; // Timer to track minutes elapsed
        // Step 2: Perform BFS
        while(!q.empty()) {
            int size = q.size(); // Store the number of rotten oranges in the current minute
            bool newRotten = false;  // Track if any fresh orange gets rotten in this step
                for(int i = 0; i < size; i++) {
                auto [x, y] = q.front(); // Current rotten orange position
                q.pop();

                // Try to rot adjacent fresh oranges
                for(auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    // If within bounds and the orange is fresh, rot it
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;  // Mark as rotten
                        q.push({nx, ny});  // Add newly rotten orange to queue
                        freshOranges--;    // Reduce fresh orange count
                        newRotten = true;
                    }
                }
            }

            if(newRotten) minutes++; // Increase time if any new oranges rotted in this step
        }

        // Step 3: If all fresh oranges are rotten, return minutes; otherwise, return -1
        return (freshOranges == 0) ? minutes : -1;
    }
};
