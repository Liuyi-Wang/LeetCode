class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            if (val != nums[r]) {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
