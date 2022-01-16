/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> counts(n, 1);
        int len = 1;
        int result = 1;
        counts[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        counts[i] = counts[j];
                    } else if (dp[i] == dp[j]+1) {
                        counts[i] += counts[j];
                    }
                }
            }
            if (len < dp[i]) {
                len = dp[i];
                result = counts[i];
            } else if (len == dp[i]) {
                result += counts[i];
            }
        }
        return result;
    }
};
