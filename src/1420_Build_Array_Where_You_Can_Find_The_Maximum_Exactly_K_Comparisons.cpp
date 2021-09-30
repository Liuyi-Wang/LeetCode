class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int M = 1e9+7;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));
        for (int i = 1; i <= m; ++i) {
            dp[1][i][1] = 1;
        }
        for (int in = 2; in <= n; ++in) {
            for (int im = 1; im <= m; ++im) {
                for (int ik = 1; ik <= k; ++ik) {
                    for (int i = 1; i < im; ++i) {
                        dp[in][im][ik] = (dp[in][im][ik]+dp[in-1][i][ik-1])%M;
                    }
                    dp[in][im][ik] = (dp[in][im][ik]+im*dp[in-1][im][ik])%M;
                }
            }
        }
        long long result = 0;
        for (int im = 1; im <= m; ++im) {
            result = (result+dp[n][im][k])%M;
        }
        return result;
    }
};
