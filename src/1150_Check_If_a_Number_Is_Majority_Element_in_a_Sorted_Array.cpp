static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (nums[m] == target) {
                r = m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        int low = -1;
        if (nums[l] == target) {
            low = l;
        } else if (nums[r] == target) {
            low = r;
        }
        if (-1 == low) {
            return false;
        }
        l = 0;
        r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (nums[m] == target) {
                l = m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        int high;
        if (nums[r] == target) {
            high = r;
        } else {
            high = l;
        }
        return (high-low+1)>nums.size()/2;
    } 
};
