class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    // use row 0 to mark columns that should set to all zeros
                    matrix[0][c] = 0;

                    if (r == 0) {
                        rowZero = true; // row zero should only used to mark columns. If itself needs to be set to all zeros, use another boolean to track
                    }
                    else {
                        matrix[r][0] = 0; // use column[0] to mark rows that should set to all zeros
                    }
                }
            }
        }

        for(int r = 1; r < m; ++r) {
            for(int c = 1; c < n; ++c) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for(int r = 0; r < m; ++r) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for(int c = 0; c < n; ++c) {
                matrix[0][c] = 0;
            }
        }
    }
};
