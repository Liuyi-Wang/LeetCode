/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> stk;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int w;
                if (!stk.empty()) {
                    w = (i-1-stk.top()-1+1);
                } else {
                    w = i;
                }
                result = max(result, w*h);
            }
            stk.push(i);
        }
        return result;
    }
};
