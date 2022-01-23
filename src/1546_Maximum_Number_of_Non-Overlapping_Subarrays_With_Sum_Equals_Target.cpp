/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> presum(n, 0);
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            presum[i] = sum;
        }
        vector<int> dp(n, 0);
        if (target == nums[0]) {
            dp[0] = 1;
        }
        hash[presum[0]] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1];
            int sum = presum[i]-target;
            if (hash.find(sum) != hash.end()) {
                if (hash[sum] == -1) {
                    dp[i] = max(dp[i], 1);
                } else {
                    dp[i] = max(dp[i], dp[hash[sum]]+1);
                }
            }
            hash[presum[i]] = i;
        }
        return dp.back();
    }
};
