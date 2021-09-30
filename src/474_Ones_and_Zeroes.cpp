static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (const auto &str:strs) {
            int ones = count(str.begin(), str.end(), '1');
            int zeros = str.size()-ones;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp.back().back();
    }
};
