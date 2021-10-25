/**
 * dp[i][k][s]
 * s, U, H
**/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) {
            return 0;
        }
        int n = prices.size();
        if (2*k >= n) {
            int result = 0;
            for (int i = 1; i < n; ++i) {
                result += max(0, prices[i]-prices[i-1]);
            }
            return result;
        }
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k+1, vector<long long>(2, INT_MIN)));
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                if (j == 0) {
                    continue;
                }
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        long long result = 0;
        for (int j = 0; j <= k; ++j) {
            result = max(result, dp.back()[j][0]);
        }
        return result;
    }
};
