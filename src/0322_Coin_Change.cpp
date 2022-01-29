/**
 *  Time:
 *  O(nm)
 *  Space:
 *  O(m)
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (auto coin:coins) {
            if (dp.size() > coin) {
                dp[coin] = 1;
            }
        }
        for (int i = 1; i <= amount; ++i) {
            if (dp[i] != -1) {
                continue;
            }
            int mn = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                if (i-coins[j] >= 0 && dp[i-coins[j]] != -1) {
                    mn = min(mn, dp[i-coins[j]]+1);
                }
            }
            if (mn != INT_MAX) {
                dp[i] = mn;
            }
        }
        return dp.back();
    }
};
