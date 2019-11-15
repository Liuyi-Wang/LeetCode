static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            if (l < 2 || nums[l-2] != nums[r]) {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
