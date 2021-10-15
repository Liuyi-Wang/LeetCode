class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int S = 0, U = 1, H = 2;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][H] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][S] = dp[i-1][H]+prices[i];
            dp[i][U] = max(dp[i-1][U], dp[i-1][S]);
            dp[i][H] = max(dp[i-1][H], dp[i-1][U]-prices[i]);
        }
        return max(dp.back()[S], dp.back()[U]);
    }
};
