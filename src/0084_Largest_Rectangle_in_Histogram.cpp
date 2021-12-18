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
        heights.push_back(0);
        stack<int> stk;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int top = stk.top();
                stk.pop();
                int l = -1;
                if (!stk.empty()) {
                    l = stk.top();
                }
                ++l;
                int width = i-1-l+1;
                result = max(result, width*heights[top]);
            }
            stk.push(i);
        }
        return result;
    }
};
