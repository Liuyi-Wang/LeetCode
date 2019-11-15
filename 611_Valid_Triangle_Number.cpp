class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = nums.size()-1; i > 1;--i) {
            int l = 0, r = i-1;
            while (l < r) {
                if (nums[l]+nums[r] > nums[i]) {
                    result += r-l;
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return result;
    }
};
