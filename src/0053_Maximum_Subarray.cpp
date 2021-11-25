/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            sum = nums[i]+max(0, sum);
            result = max(result, sum);
        }
        return result;
    }
};
