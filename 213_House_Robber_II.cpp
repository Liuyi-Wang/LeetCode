static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        if (1 == nums.size()) {
            return nums[0];
        }
        if (2 == nums.size()) {
            return max(nums[0], nums[1]);
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        for (int i = 2; i < nums.size()-1; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][0]+nums[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][1]+nums[i]);
        }
        dp.back()[0] = max(dp[nums.size()-1-1][0], dp[nums.size()-1-2][0]+nums[nums.size()-1]);
        dp.back()[1] = dp[nums.size()-1-1][1];
        return max(dp.back()[0], dp.back()[1]);
    }
};
