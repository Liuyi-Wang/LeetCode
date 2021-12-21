/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        int result = 0;
        for (int i = n-1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                result += n-i;
            } else {
                result += stk.top()-i;
            }
            stk.push(i);
        }
        return result;
    }
};
