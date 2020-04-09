static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size();
        int n = ring.size();
        vector<vector<int>> dp(m+1, vector<int>(n, 0));
        for (int i = m-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        int steps = abs(k-j);
                        steps = min(steps, n-steps);
                        dp[i][j] = min(dp[i][j], steps+dp[i+1][k]);
                    }
                }
            }
        }
        return dp[0][0]+m;
    }
};
