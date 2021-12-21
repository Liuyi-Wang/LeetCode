/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
    int MODULE = 1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 0);
        vector<int> r(n, n-1);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                l[i] = 0;
            } else {
                l[i] = stk.top()+1;
            }
            stk.push(i);
        }
        stack<int> stkR;
        stkR.push(n-1);
        for (int i = n-2; i >= 0; --i) {
            while (!stkR.empty() && nums[stkR.top()] > nums[i]) {
                stkR.pop();
            }
            if (stkR.empty()) {
                r[i] = n-1;
            } else {
                r[i] = stkR.top()-1;
            }
            stkR.push(i);
        }
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1]+nums[i];
        }
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long suml = ((l[i]==0)?0:sum[l[i]-1]);
            long long temp = (long long)nums[i]*(sum[r[i]]-suml);
            result = max(result, temp);
        }
        return result%MODULE;
    }
};
