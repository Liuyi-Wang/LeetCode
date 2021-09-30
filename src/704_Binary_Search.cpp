static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = l+(r-l)/2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return nums[l]==target?l:(-1);
    }
};
