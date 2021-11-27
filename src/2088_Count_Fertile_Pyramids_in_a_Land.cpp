class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int len = 1;
                int l = j-1, r = j+1;
                while (l >= 0 && r < n && grid[i][l] == 1 && grid[i][r] == 1) {
                    len += 2;
                    --l;
                    ++r;
                }
                dp[i][j] = len;
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int len = 1;
                for (int k = i-1; k >= 0; --k) {
                    if (dp[k][j] >= len+2) {
                        ++result;
                        len += 2;
                    } else {
                        break;
                    }
                }
                len = 1;
                for (int k = i+1; k < m; ++k) {
                    if (dp[k][j] >= len+2) {
                        ++result;
                        len += 2;
                    } else {
                        break;
                    }
                }
            }
        }
        return result;
    }
};
