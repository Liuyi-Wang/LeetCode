static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (0 == nums.size()) {
            return -1;
        }
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (target == nums[m]) {
                return m;
            }
            if (nums[l] < nums[m]) {
                if (nums[l] <= target && target <= nums[m]) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            if (nums[m] < nums[r]) {
                if (nums[m] <= target && target <= nums[r]) {
                    l = m;
                } else {
                    r = m-1;
                }
            }
        }
        if (target == nums[l]) {
            return l;
        }
        if (target == nums[r]) {
            return r;
        }
        return -1;
    }
};
