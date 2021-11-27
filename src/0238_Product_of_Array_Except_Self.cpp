/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result = {1};
        for (int i = 1; i < nums.size(); ++i) {
            result.push_back(result.back()*nums[i-1]);
        }
        int prod = 1;
        for (int i = nums.size()-2; i >= 0; --i) {
            prod *= nums[i+1];
            result[i] *= prod;
        }
        return result;
    }
};
