static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i) {
            int count = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                if (i-coins[j] < 0) {
                    break;
                }
                if (dp[i-coins[j]] == -1) {
                    continue;
                }
                count = min(count, dp[i-coins[j]]+1);
            }
            if (INT_MAX != count) {
                dp[i] = count;
            }
        }
        return dp.back();
    }
};
