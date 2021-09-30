static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        if (0 == n) {
            return 0;
        }
        vector<int> dp(n+1, 0);
        int result = 0;
        for (int j = 0; j < n; ++j) {
            if ('1' == matrix[0][j]) {
                dp[j+1] = 1;
                result = max(result, dp[j+1]);
            }
        }
        for (int i = 1; i < m; ++i) {
            vector<int> t = dp;
            for (int j = 0; j < n; ++j) {
                if ('0' == matrix[i][j]) {
                    dp[j+1] = 0;
                    continue;
                }
                dp[j+1] = min(min(dp[j], t[j+1]), t[j])+1;
                result = max(result, dp[j+1]);
            }
        }
        return result*result;
    }
};
