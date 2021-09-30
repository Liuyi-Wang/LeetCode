static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) {
            return false;
        }
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
            if (!dp[i][0]) {
                break;
            }
        }
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
            if (!dp[0][j]) {
                break;
            }
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i-1] == s3[i+j-1] && dp[i-1][j]) {
                    dp[i][j] = true;
                }
                if (s2[j-1] == s3[i+j-1] && dp[i][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp.back().back();
    }
};
