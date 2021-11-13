class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> result(n, 0);
        stk.push(n-1);
        for (int i = n-2; i >= 0; --i) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                result[i] = stk.top()-i;
            }
            stk.push(i);
        }
        return result;
    }
};
