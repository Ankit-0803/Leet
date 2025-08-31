class Solution {
public:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = col[j][num] = box[(i / 3) * 3 + j / 3][num] = true;
                }
            }
        }
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return backtrack(board, r + 1, 0);
        if (board[r][c] != '.') return backtrack(board, r, c + 1);

        for (int num = 0; num < 9; num++) {
            if (!row[r][num] && !col[c][num] && !box[(r / 3) * 3 + c / 3][num]) {
                board[r][c] = '1' + num;
                row[r][num] = col[c][num] = box[(r / 3) * 3 + c / 3][num] = true;

                if (backtrack(board, r, c + 1)) return true;

                board[r][c] = '.';
                row[r][num] = col[c][num] = box[(r / 3) * 3 + c / 3][num] = false;
            }
        }
        return false;
    }
};