/**
 *  Time:
 *  O(mnn)
 *  Space:
 *  O(mnn)
 */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0].back() = grid[0][0]+grid[0].back();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int last = -1;
                    for (int r1 = j-1; r1 <= j+1; ++r1) {
                        for (int r2 = k-1; r2 <= k+1; ++r2) {
                            if (r1 >= 0 && r2 >= 0 && r1 < n && r2 < n) {
                                last = max(last, dp[i-1][r1][r2]);
                            }
                        }
                    }
                    if (last != -1) {
                        if (j == k) {
                            dp[i][j][k] = last+grid[i][j];
                        } else {
                            dp[i][j][k] = last+grid[i][j]+grid[i][k];
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result = max(result, dp.back()[j][k]);
            }
        }
        return result;
    }
};
