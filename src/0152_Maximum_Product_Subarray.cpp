/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long lastPos = nums[0];
        long long lastNeg = nums[0];
        long long result = nums[0];
        for (int i = 1; i < n; ++i) {
            long long pos = max(lastPos*nums[i], (long long)nums[i]);
            pos = max(pos, lastNeg*nums[i]);
            long long neg = min(lastPos*nums[i], (long long)nums[i]);
            neg = min(neg, lastNeg*nums[i]);
            result = max(result, pos);
            lastPos = pos;
            lastNeg = neg;
        }
        return result;
    }
};
