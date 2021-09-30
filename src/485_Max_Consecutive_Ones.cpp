static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 == nums[i]) {
                result = max(result, count);
                count = 0;
            } else {
                ++count;
            }
        }
        return max(result, count);
    }
};
