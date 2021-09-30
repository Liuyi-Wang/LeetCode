class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                int sum = A[i-1][j]+A[i][j];
                if (j-1 >= 0) {
                    sum = min(sum, A[i-1][j-1]+A[i][j]);
                }
                if (j+1 < A[i].size()) {
                    sum = min(sum, A[i-1][j+1]+A[i][j]);
                }
                A[i][j] = sum;
            }
        }
        int result = INT_MAX;
        for (const auto a:A.back()) {
            result = min(result, a);
        }
        return result;
    }
};
