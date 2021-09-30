class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long>> dp(L+1, vector<long long>(N+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < L+1; ++i) {
            for (int j = 1; j < N+1; ++j) {
                dp[i][j] = (dp[i-1][j-1]*(N-j+1)+dp[i-1][j]*max(0, j-K))%1000000007;
            }
        }
        return dp.back().back();
    }
};
