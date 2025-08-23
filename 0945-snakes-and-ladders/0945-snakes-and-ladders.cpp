class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // min_rolls[i] = minimum number of dice throws to reach square i
        // Initialized with -1 (meaning not visited yet)
        vector<int> min_rolls(n * n + 1, -1);

        // Standard BFS queue
        queue<int> q;
        // Start from square 1 with 0 rolls
        min_rolls[1] = 0;
        q.push(1);
        // BFS traversal
        while (!q.empty()) {
            int x = q.front(); // current square
            q.pop();
            // Try all dice outcomes (1 to 6 steps ahead)
            for (int dice = 1; dice <= 6 && x + dice <= n * n; dice++) {
                int t = x + dice; // tentative square number
                // Convert "t" (1-based) to board coordinates
                int row = (t - 1) / n;     // row index from bottom
                int col = (t - 1) % n;     // column index (before zigzag adjustment)

                // Because board is top-down and zigzag:
                // - from bottom row: left→right
                // - next row: right→left
                // So we flip row and possibly flip col
                int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                // If there is a snake/ladder, move to its destination
                // Otherwise stay at t
                int y = (v > 0) ? v : t;
                // If we reached the goal square → return moves count
                if (y == n * n)
                    return min_rolls[x] + 1;
                    // If not visited, record moves and enqueue
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);
                }
            }
        }
        // If BFS finishes without reaching n*n, it's impossible
        return -1;
    }
};
