/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int h = min(height[i], height[stk.top()])-height[top];
                result += h*(i-1-stk.top()-1+1);
            }
            stk.push(i);
        }
        return result;
    }
};
