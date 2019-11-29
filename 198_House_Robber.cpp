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
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};
