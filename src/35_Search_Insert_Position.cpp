class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (0 == nums.size()) {
            return 0;
        }
        if (target < nums[0]) {
            return 0;
        }
        if (target > nums.back()) {
            return nums.size();
        }
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (target == nums[m]) {
                return m;
            } else if (target < nums[m]) {
                r = m-1;
            } else {
                l = m;
            }
        }
        if (target == nums[l]) {
            return l;
        }
        if (target == nums[r]) {
            return r;
        }
        if (target > nums[r]) {
            return r+1;
        }
        return l+1;
    }
};
