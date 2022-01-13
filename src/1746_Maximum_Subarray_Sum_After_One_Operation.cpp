/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0]*nums[0];
        int n = nums.size();
        int result = dp[0][1];
        for (int i = 1; i < n; ++i) {
            int cur = i%2;
            int pre = (cur+1)%2;
            // Not do operation
            dp[cur][0] = max(0, dp[pre][0])+nums[i];
            if (dp[pre][1] > 0) {
                dp[cur][1] = dp[pre][1]+nums[i];
            }
            // Do operation
            dp[cur][1] = max(dp[cur][1], max(0, dp[pre][0])+nums[i]*nums[i]);
            result = max(result, dp[cur][1]);
        }
        return result;
    }
};
