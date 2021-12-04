/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int result = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    result = max(result, h*(i-1-stk.top()-1+1));
                } else {
                    result = max(result, h*(i-1+1));
                }
            }
            stk.push(i);
        }
        return result;
    }
};
