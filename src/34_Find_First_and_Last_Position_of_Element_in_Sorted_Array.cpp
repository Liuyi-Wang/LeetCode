static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (0 == nums.size()) {
            return result;
        }
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (target == nums[m]) {
                r = m;
            } else if (target < nums[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (target == nums[l]) {
            result[0] = l;
            result[1] = l;
        } else if (target == nums[r]) {
            result[0] = r;
            result[1] = r;
        } else {
            return result;
        }
        l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (target == nums[m]) {
                l = m;
            } else if (target > nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (target == nums[r]) {
            result[1] = r;
        } else {
            result[1] = l;
        }
        return result;
    }
};
