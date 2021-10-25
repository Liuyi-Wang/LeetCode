/**
 ** dp[i][j][k]
 ** i, first i housed
 ** j, j th color to paint
 ** k, has k+1 neighborhoods
 ** Intuition
 ** We have m houses, and n colors. These are two dimentions in dp.
 ** Now, we need to construct target neighborhoods.
 ** And if we construct a new neighborhoods when we paint on ith house,
 ** only depend on how we paint i-1th house.
 ** So add neighborhoods as the third dimention.
**/
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, -1)));
        // For the first house
        if (houses[0] == 0) {
            for (int j = 0; j < n; ++j) {
                dp[0][j][0] = cost[0][j];
            }
        } else {
            dp[0][houses[0]-1][0] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < target; ++k) {
                        // Paint with the same color as i-1
                        if (dp[i-1][j][k] != -1) {
                            dp[i][j][k] = dp[i-1][j][k]+cost[i][j];
                        }
                        if (k == 0) {
                            continue;
                        }
                        // Paint with different color from i-1
                        for (int l = 0; l < n; ++l) {
                            if (l == j) {
                                continue;
                            }
                            if (dp[i-1][l][k-1] == -1) {
                                continue;
                            }
                            if (dp[i][j][k] == -1) {
                                dp[i][j][k] = dp[i-1][l][k-1]+cost[i][j];
                            } else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k-1]+cost[i][j]);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i]-1;
                for (int k = 0; k < target; ++k) {
                    // Paint with the same color as i-1
                    if (dp[i-1][j][k] != -1) {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                    if (k == 0) {
                        continue;
                    }
                    // Paint with different color from i-1
                    for (int l = 0; l < n; ++l) {
                        if (l == j) {
                            continue;
                        }
                        if (dp[i-1][l][k-1] == -1) {
                            continue;
                        }
                        if (dp[i][j][k] == -1) {
                            dp[i][j][k] = dp[i-1][l][k-1];
                        } else {
                            dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k-1]);
                        }
                    }
                }
            }
        }
        int result = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (dp.back()[j].back() != -1) {
                result = min(result, dp.back()[j].back());
            }
        }
        return (result==INT_MAX)?(-1):result;
    }
};
