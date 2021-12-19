/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<int> stk;
        int num = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (preorder[i] < num) {
                return false;
            }
            while (!stk.empty() && stk.top() < preorder[i]) {
                num = max(num, stk.top());
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        return true;
    }
};
