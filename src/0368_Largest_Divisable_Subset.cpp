/**
 *  Time:
 *  O(n*n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n, {1, -1});
        int result = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i]%nums[j] == 0) {
                    if (dp[i].first < dp[j].first+1) {
                        dp[i].first = dp[j].first+1;
                        dp[i].second = j;
                    }
                }
            }
            if (dp[result].first < dp[i].first) {
                result = i;
            }
        }
        vector<int> v;
        v.push_back(nums[result]);
        while (dp[result].second != -1) {
            result = dp[result].second;
            v.push_back(nums[result]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
