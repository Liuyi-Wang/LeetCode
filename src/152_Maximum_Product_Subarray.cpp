class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        if (nums[0] > 0) {
            dp[0][0] = nums[0];
        } else if (nums[0] < 0) {
            dp[0][1] = nums[0];
        }
        long long result = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                if (dp[i-1][0] == 0) {
                    dp[i][0] = nums[i];
                } else {
                    dp[i][0] = dp[i-1][0]*nums[i];
                }
                if (dp[i-1][1] != 0) {
                    dp[i][1] = dp[i-1][1]*nums[i];
                }
            } else if (nums[i] < 0) {
                if (dp[i-1][1] != 0) {
                    dp[i][0] = dp[i-1][1]*nums[i];
                }
                if (dp[i-1][0] == 0) {
                    dp[i][1] = nums[i];
                } else {
                    dp[i][1] = dp[i-1][0]*nums[i];
                }
            }
            result = max(result, dp[i][0]);
        }
        return result;
    }
};
