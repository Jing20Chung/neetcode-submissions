class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        m = std::ssize(matrix);
        n = std::ssize(matrix[0]);

        prefixSum2D = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                prefixSum2D[r + 1][c + 1] = prefixSum2D[r + 1][c] + prefixSum2D[r][c + 1] + matrix[r][c] - prefixSum2D[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || col1 < 0 || row1 >= m || col1 >= n || row1 > row2 || col1 > col2 ) return 0;
        return prefixSum2D[row2 + 1][col2 + 1] - prefixSum2D[row2 + 1][col1] - prefixSum2D[row1][col2 + 1] + prefixSum2D[row1][col1];
    }
private:
    vector<vector<int>> prefixSum2D;
    int m, n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */