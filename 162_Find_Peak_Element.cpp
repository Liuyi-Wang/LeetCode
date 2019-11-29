class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (nums[m] > nums[m+1]) {
                r = m;
            } else {
                l = m+1;
            }
        }
        if (nums[l] > nums[r]) {
            r = l;
        }
        return r;
    }
};
