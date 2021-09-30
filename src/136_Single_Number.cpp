static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;
    }
};
