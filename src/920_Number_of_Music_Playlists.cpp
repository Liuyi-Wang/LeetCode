class Solution {
public:
    int MODULO = 1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<unsigned long long>> dp(goal+1, vector<unsigned long long>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i-1][j-1]*(n-j+1)+dp[i-1][j]*(max(j-k, 0));
                dp[i][j] %= MODULO;
            }
        }
        return dp.back().back();
    }
};
