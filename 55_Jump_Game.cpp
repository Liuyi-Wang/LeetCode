class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        int i = 0;
        for (; i <= end; ++i) {
            if (end >= nums.size()-1) {
                return true;
            }
            end = max(end, i+nums[i]);
        }
        return false;
    }
};
