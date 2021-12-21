/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
    int MODULE = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> l(n, 1);
        vector<long long> r(n, 1);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                l[i] = i+1;
            } else {
                l[i] = i-stk.top();
            }
            stk.push(i);
        }
        stack<int> stkR;
        stkR.push(n-1);
        for (int i = n-2; i >= 0; --i) {
            while (!stkR.empty() && arr[stkR.top()] > arr[i]) {
                stkR.pop();
            }
            if (stkR.empty()) {
                r[i] = n-1-i+1;
            } else {
                r[i] = stkR.top()-i;
            }
            stkR.push(i);
        }
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += l[i]*r[i]*arr[i];
            result %= MODULE;
        }
        return result;
    }
};
