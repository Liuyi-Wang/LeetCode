class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int result = sum;
        for (int i = 1; i < nums.size(); ++i) {
            result = max(result, sum);
            if (sum >= 0) {
                sum += nums[i];
            } else {
                sum = nums[i];    
            }
        }
        result = max(result, sum);
        return result;
    }
};
