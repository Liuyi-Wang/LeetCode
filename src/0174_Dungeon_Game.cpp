/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(nn)
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        if (dungeon[m-1][n-1] < 0) {
            dp[m-1][n-1] -= dungeon[m-1][n-1];
        }
        for (int i = m-2; i >= 0; --i) {
            dp[i].back() = max(1, dp[i+1].back()-dungeon[i].back());
        }
        for (int j = n-2; j >= 0; --j) {
            dp.back()[j] = max(1, dp.back()[j+1]-dungeon.back()[j]);
        }
        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                int r = max(1, dp[i+1][j]-dungeon[i][j]);
                int d = max(1, dp[i][j+1]-dungeon[i][j]);
                dp[i][j] = min(r, d);
            }
        }
        return dp[0][0];
    }
};

