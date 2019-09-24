class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1]+nums[i-1];
        }
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = i-1; k < j; ++k) {
                    long long val = max(sum[j]-sum[k], dp[i-1][k]);
                    dp[i][j] = min(dp[i][j], val);
                }    
            }
        }
        return dp[m][n];
    }
};
