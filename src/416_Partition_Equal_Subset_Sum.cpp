static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum%2 == 1) {
            return false;
        }
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum/2; j-nums[i] >= 0; --j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp.back();
    }
};
