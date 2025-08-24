class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        // Boundary check and stop if not 'O'
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;

        board[i][j] = '#';  // mark safe

        // Explore 4 directions
        dfs(board, i+1, j, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i, j-1, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: Mark border-connected 'O's
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n-1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j, m, n);
            dfs(board, m-1, j, m, n);
        }

        // Step 2: Flip and restore
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
