/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        int maxa = INT_MIN;
        for (auto a:arr) {
            if (maxa <= a) {
                stk.push(a);
                maxa = a;
                continue;
            }
            while (!stk.empty() && stk.top() > a) {
                stk.pop();
            }
            stk.push(maxa);
        }
        return stk.size();
    }
};
