static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int l = 0, r = dp.size()-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (dp[m] >= nums[i]) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            if (dp[l] >= nums[i]) {
                dp[l] = nums[i];
            } else if (dp[r] >= nums[i]) {
                dp[r] = nums[i];
            } else {
                dp.push_back(nums[i]);
            }
        }
        return dp.size();
    }
};
