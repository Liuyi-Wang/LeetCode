class Solution {
public:
    int knightDialer(int N) {
        if (1 == N) {
            return 10;
        }
        vector<vector<long long>> dp(5, vector<long long>(N, 1));
        for (int j = 1; j < N; ++j) {
            dp[0][j] = dp[4][j-1]*2%(1000000007);
            dp[1][j] = (dp[4][j-1]+dp[2][j-1])%(1000000007);
            dp[2][j] = (dp[1][j-1]+dp[3][j-1])%(1000000007);
            dp[3][j] = (dp[4][j-1]+dp[2][j-1])%(1000000007);
            dp[4][j] = (dp[3][j-1]+dp[1][j-1]+dp[0][j-1])%(1000000007);
        }
        long long result = 0;
        for (int i = 1; i < 5; ++i) {
            result += dp[i][N-1];
        }
        return (result*2+dp[0][N-1])%(1000000007);
    }
};
