class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, b = nums.size()-1;
        for (int i = 0; i <= b;) {
            if (0 == nums[i]) {
                swap(nums[r], nums[i]);
                ++r;
                ++i;
            } else if (2 == nums[i]) {
                swap(nums[b], nums[i]);
                --b;
            } else {
                ++i;
            }
        }
    }
};
