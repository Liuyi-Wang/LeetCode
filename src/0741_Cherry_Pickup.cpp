/**
 *  Time:
 *  O(nnn)
 *  Space:
 *  O(nnn)
 */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int x = 0; x <= n; ++x) {
                    dp[i][j][x] = INT_MIN;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int x = 1; x <= n; ++x) {
                    int y = i+j-x;
                    if (y < 1 || y > n) {
                        continue;
                    }
                    if (grid[i-1][j-1] == -1 || grid[x-1][y-1] == -1) {
                        continue;
                    }
                    if (i == 1 && j == 1) {
                        dp[i][j][x] = grid[i-1][j-1];
                        continue;
                    }
                    dp[i][j][x] = max(dp[i][j][x], dp[i-1][j][x-1]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x-1]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i-1][j][x]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x]);
                    
                    if (i == x) {
                        dp[i][j][x] += grid[i-1][j-1];
                    } else {
                        dp[i][j][x] += grid[i-1][j-1]+grid[x-1][y-1];
                    }
                }
            }
        }
        return max(0, dp[n][n][n]);
    }
};
