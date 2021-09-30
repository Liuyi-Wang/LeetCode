static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            if (0 != nums[r]) {
                swap(nums[l++], nums[r]);
            }
        }
    }
};
