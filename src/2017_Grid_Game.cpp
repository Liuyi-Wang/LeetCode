class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> dp(2, vector<long long>(n, 0));
        for (int i = 1; i < n; ++i) {
            dp[1][i] = grid[1][i-1] + dp[1][i-1];
        }
        for (int i = n-2; i >= 0; --i) {
            dp[0][i] = grid[0][i+1] + dp[0][i+1];
        }
        long long result = min(dp[0][0], dp[1][n-1]);
        for (int i = 1; i < n-1; ++i) {
            long long temp = max(dp[0][i], dp[1][i]);
            result = min(result, temp);
        }
        return result;
    }
};
