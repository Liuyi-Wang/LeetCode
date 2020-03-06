class Solution {
public:
    int integerBreak(int n) {
        if (2 == n) {
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i < n+1; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], j*(i-j));
                dp[i] = max(dp[i], j*dp[i-j]);
            }
        }
        return dp.back();
    }
};
