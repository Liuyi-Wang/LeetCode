class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int pos = nums[0], neg = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tp = pos, tn = neg;
            pos = max(max(nums[i], tp*nums[i]), tn*nums[i]);
            neg = min(min(nums[i], tn*nums[i]), tp*nums[i]);
            result = max(result, pos);
        }
        return result;
    }
};
