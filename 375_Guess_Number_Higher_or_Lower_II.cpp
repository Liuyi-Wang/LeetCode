static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 2; i <= n; ++i) {
            for (int j = i-1; j >= 1; --j) {
                int min_choice = INT_MAX;
                for (int k = j+1; k < i; ++k) {
                    int max_cost = k+max(dp[j][k-1], dp[k+1][i]);
                    min_choice = min(min_choice, max_cost);
                }
                if (i == j+1) {
                    dp[j][i] = j;
                } else {
                    dp[j][i] = min_choice;
                }
            }
        }
        return dp[1].back();
    }
};
