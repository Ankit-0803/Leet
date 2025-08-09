class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();          // Number of rows
        int n = matrix[0].size();       // Number of columns
        bool col0 = false;              // Flag to indicate if first column should be zero

        // Step 1: Use first row and first column as markers
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;  // Check if first column has zero
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // Mark row i to be zeroed
                    matrix[0][j] = 0;   // Mark column j to be zeroed
                }
            }
        }

        // Step 2: Iterate from bottom-right to top-left to avoid overwriting markers early
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                // If either the row or column is marked, set element to zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // If first column was originally zero, zero out this cell
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};
