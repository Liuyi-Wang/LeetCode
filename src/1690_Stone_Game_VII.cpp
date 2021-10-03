class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n+1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i-1] + stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = max(sum[j+1]-sum[i+1]-dp[i+1][j], sum[j]-sum[i]-dp[i][j-1]);
            }
        }
        return dp[0].back();
    }
};
