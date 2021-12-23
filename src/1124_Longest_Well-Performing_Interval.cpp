/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) {
                hours[i] = 1;
            } else {
                hours[i] = -1;
            }
            if (i == 0) {
                sum[i] = hours[i];
            } else {
                sum[i] = sum[i-1]+hours[i];
            }
        }
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; ++i) {
            if (sum[stk.top()] > sum[i]) {
                stk.push(i);
            }
        }
        int result = 0;
        for (int i = n-1; i >= 0; --i) {
            if (stk.empty()) {
                break;
            }
            if (sum[i] > 0) {
                result = max(result, i+1);
            }
            while (!stk.empty() && sum[stk.top()] < sum[i]) {
                result = max(result, i-stk.top());
                stk.pop();
            }
        }
        return result;
    }
};
