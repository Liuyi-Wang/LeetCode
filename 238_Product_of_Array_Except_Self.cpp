class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int p = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result[i] *= p;
            p *= nums[i];
        }
        p = nums.back();
        for (int i = nums.size()-2; i >= 0; --i) {
            result[i] *= p;
            p *= nums[i];
        }
        return result;
    }
};
