class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(d, INT_MAX));
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], jobDifficulty[i]);
        }
        for (int c = 1; c < d; ++c) {
            for (int i = c; i < n; ++i) {
                int m = jobDifficulty[i];
                for (int j = i-1; j >= c-1; --j) {
                    dp[i][c] = min(dp[i][c], m+dp[j][c-1]);
                    m = max(m, jobDifficulty[j]);
                }
            }
        }
        return dp.back().back();
    }
};
