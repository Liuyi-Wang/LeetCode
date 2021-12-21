/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }
        int result = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (stk.empty()) {
                break;
            }
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                result = max(result, i-stk.top());
                stk.pop();
            }
        }
        return result;
    }
};
