/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        vector<vector<long long>> dp(2, vector<long long>(2, -1));
        dp[0][0] = nums[0];
        long long result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int cur = i%2;
            int pre = (cur+1)%2;
            
            dp[cur][0] = max((long long)nums[i], nums[i]+dp[pre][1]);
            dp[cur][1] = dp[pre][0]-nums[i];
            
            result = max(result, dp[cur][0]);
            result = max(result, dp[cur][1]);
        }
        return result;
    }
};
