class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if (0 != (n-1)%(K-1)) {
            return -1;
        }
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1]+stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = K; len <= n; ++len) {
            for (int i = 0; i < n-len+1; ++i) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k += K-1) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
                if (0 == (j-i)%(K-1)) {
                    dp[i][j] += sum[j+1]-sum[i];
                }
            }
        }
        return dp[0][n-1];
    }
};
