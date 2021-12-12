/**
 *  Time:
 *  O(mn)
 *  Space:
 *  O(m)
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num:nums) {
            sum += num;
        }
        if (sum%2 != 0) {
            return false;
        }
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int s = sum/2; s > 0; --s) {
                if (s-nums[i] >= 0 && dp[s-nums[i]]) {
                    dp[s] = true;
                }
            }
        }
        return dp.back();
    }
};
