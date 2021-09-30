static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i+j*j <= n; ++j) {
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }
        return dp.back();
    }
};
