class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][i] = nums[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                dp[i][i+len-1] = max(nums[i]-dp[i+1][i+len-1], nums[i+len-1]-dp[i][i+len-2]);
            }
        }
        return dp[0].back()>=0;
    }
};
