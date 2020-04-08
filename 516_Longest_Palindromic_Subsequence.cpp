static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                dp[i-1][i] = 2;
            }
            for (int j = i-2; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[j][i] = 2+dp[j+1][i-1];
                } else {
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
                }
            }
        }
        return dp[0].back();
    }
};
