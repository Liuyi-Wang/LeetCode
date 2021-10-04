class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        vector<int> directions = {-1, 0, 1};
        int result = 0;
        for (int r = 1; r < m; ++r) {
            int prev = (r-1)%2;
            int cur = r%2;
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    dp[cur][i][j] = INT_MIN;
                    for (int k = 0; k < 3; ++k) {
                        int I = i + directions[k];
                        if (I < 0 || I >= n) {
                            continue;
                        }
                        for (int l = 0; l < 3; ++l) {
                            int J = j + directions[l];
                            if (J < 0 || J >= n) {
                                continue;
                            }
                            if (i == j) {
                                dp[cur][i][j] = max(dp[cur][i][j], grid[r][i]+dp[prev][I][J]);
                            } else {
                                dp[cur][i][j] = max(dp[cur][i][j], grid[r][i]+grid[r][j]+dp[prev][I][J]);
                            }
                            result = max(result, dp[cur][i][j]);
                        }
                    }
                }
            }
        }
        return result;
    }
};
