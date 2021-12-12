/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> l2r(n, 0);
        vector<int> r2l(n, 0);
        int day = 0;
        for (int i = 1; i < n; ++i) {
            if (security[i-1] >= security[i]) {
                ++day;
            } else {
                day = 0;
            }
            l2r[i] = day;
        }
        day = 0;
        for (int i = n-2; i >= 0; --i) {
            if (security[i+1] >= security[i]) {
                ++day;
            } else {
                day = 0;
            }
            r2l[i] = day;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (l2r[i] >= time && r2l[i] >= time) {
                result.push_back(i);
            }
        }
        return result;
    }
};
