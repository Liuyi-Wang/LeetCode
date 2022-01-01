/**
 *  Time:
 *  O(n^2)
 *  Space:
 *  O(n^2)
 */
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size();
        int k = days[0].size();
        vector<vector<int>> dp(n, vector<int>(k, -1));
        vector<vector<int>> connectFrom(n, vector<int>());
        dp[0][0] = days[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < flights[i].size(); ++j) {
                if (flights[i][j] == 1) {
                    connectFrom[j].push_back(i);
                    if (i == 0) {
                        dp[j][0] = days[j][0];
                    }
                }
            }
        }
        for (int j = 1; j < k; ++j) {
            for (int i = 0; i < n; ++i) {
                if (dp[i][j-1] != -1) {
                    dp[i][j] = dp[i][j-1]+days[i][j];
                }
                for (int l = 0; l < connectFrom[i].size(); ++l) {
                    if (dp[connectFrom[i][l]][j-1] != -1) {
                        dp[i][j] = max(dp[i][j], dp[connectFrom[i][l]][j-1]+days[i][j]);
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, dp[i].back());
        }
        return result;
    }
};
