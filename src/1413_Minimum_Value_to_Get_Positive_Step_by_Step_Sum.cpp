class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prev = 1-nums.back();
        for (int i = static_cast<int>(nums.size())-2; i >= 0; --i) {
            int t = max(1, prev);
            prev = t-nums[i];
        }
        return max(prev, 1);
    }
};
