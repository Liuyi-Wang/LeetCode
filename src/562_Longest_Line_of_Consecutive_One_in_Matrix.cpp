static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size();
        if (0 == m) {
            return 0;
        }
        int n = M[0].size();
        if (0 == n) {
            return 0;
        }
        int dp[m][n][4];
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == M[i][j]) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                    dp[i][j][2] = 0;
                    dp[i][j][3] = 0;
                    continue;
                }
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
                dp[i][j][2] = 1;
                dp[i][j][3] = 1;
                if (i > 0) {
                    dp[i][j][0] += dp[i-1][j][0];
                }
                if (j > 0) {
                    dp[i][j][1] += dp[i][j-1][1];
                }
                if (i > 0 && j > 0) {
                    dp[i][j][2] += dp[i-1][j-1][2];
                }
                if (i > 0 && j < n-1) {
                    dp[i][j][3] += dp[i-1][j+1][3];
                }
                result = max(result, dp[i][j][0]);
                result = max(result, dp[i][j][1]);
                result = max(result, dp[i][j][2]);
                result = max(result, dp[i][j][3]);
            }
        }
        return result;
    }
};
