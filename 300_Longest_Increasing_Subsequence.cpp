class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return sol1(nums);
    }
    
    int sol1(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }       
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
