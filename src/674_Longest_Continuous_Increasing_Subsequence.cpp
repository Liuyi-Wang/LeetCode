static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        int l = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++l;
            } else {
                result = max(result, l);
                l = 1;
            }
        }
        return max(result, l);
    }
};
