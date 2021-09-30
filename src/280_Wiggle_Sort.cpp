static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (1==i%2 && nums[i-1] > nums[i]) {
                swap(nums[i-1], nums[i]);
            } else if (0==i%2 && nums[i-1] < nums[i]) {
                swap(nums[i-1], nums[i]);
            }
        }
    }
};
