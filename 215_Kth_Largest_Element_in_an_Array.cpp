static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int solve(vector<int> &nums, int begin, int end, int k) {
        int p = end;
        int last = begin;
        for (int i = begin; i < p; ++i) {
            if (nums[i] >= nums[p]) {
                swap(nums[last], nums[i]);
                ++last;
            }
        }
        swap(nums[last], nums[p]);
        if (k == last-begin+1) {
            return nums[last];
        }
        if (k > last-begin+1) {
            return solve(nums, last+1, end, k-(last-begin+1));
        }
        return solve(nums, begin, last-1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, 0, nums.size()-1, k);
    }
};
