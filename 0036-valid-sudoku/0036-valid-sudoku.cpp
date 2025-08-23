class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Each row, column, and box has a hash set to track used numbers
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        // Traverse all cells of the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];

                // Skip empty cells
                if (val == '.') continue;

                // 1. Check row constraint
                if (rows[i].count(val)) return false;
                rows[i].insert(val);

                // 2. Check column constraint
                if (cols[j].count(val)) return false;
                cols[j].insert(val);

                // 3. Check 3x3 sub-box constraint
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(val)) return false;
                boxes[boxIndex].insert(val);
            }
        }

        // If no violations found, board is valid
        return true;
    }
};
