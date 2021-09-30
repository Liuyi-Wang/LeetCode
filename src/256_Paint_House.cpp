static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (0 == costs.size()) {
            return 0;
        }
        vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i = 1; i < costs.size(); ++i) {
            dp[i][0] = costs[i][0]+min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1]+min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2]+min(dp[i-1][0], dp[i-1][1]);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};
