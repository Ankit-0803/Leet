class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Directions for 8 neighbors
        vector<pair<int,int>> dirs = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        // Step 1: Apply rules with temporary markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                // Count live neighbors (using abs because of temporary markers)
                for (auto [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1) {
                        liveNeighbors++;
                    }
                }
                // Apply rules
                if (board[i][j] == 1) {
                    // Rule 1 or 3: Dies
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                        board[i][j] = -1; // live -> dead
                } else {
                    // Rule 4: Dead -> Live
                    if (liveNeighbors == 3)
                        board[i][j] = 2; // dead -> live
                }
            }
        }
        // Step 2: Finalize board (convert markers to 0/1)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};
