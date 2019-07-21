class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<int> row(B.size()+1, 0);
        vector<vector<int>> dp(A.size()+1, row);
        for (int i = 1; i < A.size()+1; ++i) {
            for (int j = 1; j < B.size()+1; ++j) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if (B[j-1] == A[i-1]) {
                    dp[i][j] = max(1+dp[i-1][j-1], dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};
