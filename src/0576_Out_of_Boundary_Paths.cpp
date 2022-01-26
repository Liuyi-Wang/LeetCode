/**
 *  Time:
 *  O(kmn)
 *  Space:
 *  O(mn)
 */
class Solution {
    int MODULO = 1e9+7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 1; k <= maxMove; ++k) {
            int cur = k%2;
            int pre = (cur+1)%2;
            dp[cur] = vector<vector<int>>(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                dp[cur][i][0] += 1;
                dp[cur][i].back() += 1;
            }
            for (int j = 0; j < n; ++j) {
                dp[cur][0][j] += 1;
                dp[cur].back()[j] += 1;
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int I = i+d[k].first;
                        int J = j+d[k].second;
                        if (I < 0 || J < 0 || I >= m || J >= n) {
                            continue;
                        }
                        dp[cur][i][j] += dp[pre][I][J];
                        dp[cur][i][j] %= MODULO;
                    }
                }
            }
        }
        return dp[maxMove%2][startRow][startColumn];
    }
};
