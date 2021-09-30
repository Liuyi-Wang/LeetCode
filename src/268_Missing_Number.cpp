static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /// xor 0-n, and nums[0]-nums.back()
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= i^nums[i];
        }
        return result;
    }
};
