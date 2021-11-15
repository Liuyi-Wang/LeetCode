/**
 *  Time:
 *  O(n*n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int idx = 0, count = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i]%nums[j] == 0) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > count) {
                count = dp[i];
                idx = i;
            }
        }
        vector<int> result;
        while (idx != -1) {
            result.push_back(nums[idx]);
            idx = prev[idx];
        }
        return result;
    }
};
