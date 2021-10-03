class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            num = min(num, nums[i]);
            if (nums[i] > num) {
                result = max(result, nums[i]-num);
            }
        }
        return result;
    }
};
