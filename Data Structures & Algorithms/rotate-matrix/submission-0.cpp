class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int L = 0;
        int R = matrix.size() - 1;

        while (L < R) {
            int T = L;
            int B = R;
            for (int i = 0; i < R - L; ++i) {
                int tmpTL = matrix[T][L + i];

                matrix[T][L + i] = matrix[B - i][L];
                matrix[B - i][L] = matrix[B][R - i];
                matrix[B][R - i] = matrix[T + i][R];
                matrix[T + i][R] = tmpTL;
            }
            ++L;
            --R;
        }
    }
};
