static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= s.size(); ++l) {
            for (int i = 0; i+l <= s.size(); ++i) {
                int j = i+l-1;
                dp[i][j] = dp[i+1][j]+1;
                for (int k = i+1; k <= j; ++k) {
                    if (s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j], dp[k][j]+dp[i+1][k-1]);
                    }
                }
            }
        }
        return dp[0].back();
    }
};
