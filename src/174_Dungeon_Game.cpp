class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = m-2; i >= 0; --i) {
            dp[i][n-1] = max(1, dp[i+1][n-1]-dungeon[i+1][n-1]);
        }
        for (int j = n-2; j >= 0; --j) {
            dp[m-1][j] = max(1, dp[m-1][j+1]-dungeon[m-1][j+1]);
        }
        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                int d = max(1, dp[i+1][j]-dungeon[i+1][j]);
                int r = max(1, dp[i][j+1]-dungeon[i][j+1]);
                dp[i][j] = min(d, r);
            }
        }
        return max(1, dp[0][0]-dungeon[0][0]);
    }
};

/*
Optimize: reduce space to O(min(m, n)*2), we only need previous row or col stored
Time: O(m*n)
Space: O(min(m, n)*2)
*/
