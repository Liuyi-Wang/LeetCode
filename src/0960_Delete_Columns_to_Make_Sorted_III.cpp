/**
 *  Time:
 *  O(lln)
 *  Space:
 *  O(l)
 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int l = strs[0].size();
        int n = strs.size();
        vector<int> dp(l, 1);
        int result = 1;
        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < i; ++j) {
                if (smaller(strs, j, i, n)) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            result = max(result, dp[i]);
        }
        return l - result;
    }
    
    bool smaller(const vector<string>& strs, int i, int j, int n) {
        for (int k = 0; k < n; ++k) {
            if (strs[k][i] > strs[k][j]) {
                return false;
            }
        }
        return true;
    }
};
