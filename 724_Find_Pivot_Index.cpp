static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (0 == nums.size()) {
            return -1;
        }
        vector<int> sums(nums.size(), nums[0]);
        for (int i = 1; i < sums.size(); ++i) {
            sums[i] = sums[i-1]+nums[i];
        }
        int sum = 0;
        int result = -1;
        for (int i = nums.size()-1; i >= 0; --i) {
            sum += nums[i];
            if (sum == sums[i]) {
                result = i;
            }
        }
        return result;
    }
};
