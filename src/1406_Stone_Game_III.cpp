class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sum = vector(n, 0);
        sum.back() = stoneValue.back();
        for (int i = stoneValue.size()-2; i >= 0; --i) {
            sum[i] = sum[i+1]+stoneValue[i];
        }
        vector<int> dp = vector(n, INT_MIN);
        dp.back() = stoneValue.back();
        if (n > 1) {
            dp[n-2] = max(dp[n-2], stoneValue[n-2]+sum[n-1]-dp[n-1]);
            dp[n-2] = max(dp[n-2], stoneValue[n-2]+stoneValue[n-1]);
        }
        if (n > 2) {
            dp[n-3] = max(dp[n-3], stoneValue[n-3]+sum[n-2]-dp[n-2]);
            dp[n-3] = max(dp[n-3], stoneValue[n-3]+stoneValue[n-2]+sum[n-1]-dp[n-1]);
            dp[n-3] = max(dp[n-3], stoneValue[n-3]+stoneValue[n-2]+stoneValue[n-1]);
        }
        for (int i = n-4; i >= 0; --i) {
            dp[i] = max(dp[i], stoneValue[i]+sum[i+1]-dp[i+1]);
            dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+sum[i+2]-dp[i+2]);
            dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+sum[i+3]-dp[i+3]);
        }
        if (dp[0]*2 == sum[0]) {
            return "Tie";
        }
        if (dp[0]*2 > sum[0]) {
            return "Alice";
        }
        return "Bob";
    }
};
