static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(s.size()+1, vector<long>(t.size()+1, 0));
        for (int i = 0; i < s.size()+1; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < s.size()+1; ++i) {
            for (int j = 1; j < t.size()+1; ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp.back().back();
    }
};
