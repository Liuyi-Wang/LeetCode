class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int u = 1, d = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                u = d+1;
            } else if (nums[i] < nums[i-1]) {
                d = u+1;
            }
        }
        return max(u, d);
    }
};
