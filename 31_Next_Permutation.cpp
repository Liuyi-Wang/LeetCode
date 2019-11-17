class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int i = nums.size()-2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                break;
            }
        }
        if (-1 == i) {
            sort(nums.begin(), nums.end());
            return;
        }
        int l = i+1, r = nums.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (nums[m] > nums[i]) {
                l = m;
            } else {
                r = m-1;
            }
        }
        if (nums[r] > nums[i]) {
            l = r;
        }
        swap(nums[i], nums[l]);
        sort(nums.begin()+i+1, nums.end());
    }
};
