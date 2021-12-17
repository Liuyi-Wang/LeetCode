/**
 *  Time:
 *  O(mn)
 *  Space:
 *  O(mn)
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == '0') {
                continue;
            }
            dp[i][0] = 1;
            result = 1;
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == '0') {
                continue;
            }
            dp[0][j] = 1;
            result = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                int x = min(dp[i][j-1], dp[i-1][j-1]);
                int y = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = 1+min(x, y);
                result = max(result, dp[i][j]*dp[i][j]);
            }
        }
        return result;
    }
};
