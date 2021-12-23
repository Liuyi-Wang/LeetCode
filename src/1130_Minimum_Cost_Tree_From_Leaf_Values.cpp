/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n, INT_MAX);
        vector<int> r(n, INT_MAX);
        stack<int> stk;
        stk.push(arr[0]);
        for (int i = 1; i < n; ++i) {
            while (!stk.empty() && stk.top() < arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                l[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        stack<int> stkr;
        stkr.push(arr.back());
        for (int i = n-2; i >= 0; --i) {
            while (!stkr.empty() && stkr.top() <= arr[i]) {
                stkr.pop();
            }
            if (!stkr.empty()) {
                r[i] = stkr.top();
            }
            stkr.push(arr[i]);
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int p = min(l[i], r[i]);
            if (p != INT_MAX) {
                result += p*arr[i];
            }
        }
        return result;
    }
};
