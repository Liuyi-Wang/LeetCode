/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(2, vector<int>(3, INT_MAX));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i < n; ++i) {
            int cur = i%2;
            int pre = (cur+1)%2;
            for (int j = 0; j < 3; ++j) {
                dp[cur][j] = INT_MAX;
                if (obstacles[i] == j+1) {
                    continue;
                }
                for (int k = 0; k < 3; ++k) {
                    if (j == k) {
                        dp[cur][j] = min(dp[cur][j], dp[pre][k]);
                        continue;
                    }
                    if (obstacles[i] == k+1 || obstacles[i-1] == k+1) {
                        continue;
                    }
                    dp[cur][j] = min(dp[cur][j], dp[pre][k]+1);
                }
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            result = min(result, dp[(n-1)%2][i]);
        }
        return result;
    }
};
