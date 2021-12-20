/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> vpos(n, 0);
        vector<int> vsum(n, 0);
        vpos[0] = fruits[0][0];
        vsum[0] = fruits[0][1];
        for (int i = 1; i < n; ++i) {
            vpos[i] = fruits[i][0];
            vsum[i] = vsum[i-1]+fruits[i][1];
        }
        int start = lower_bound(vpos.begin(), vpos.end(), startPos)-vpos.begin();
        int i = start;
        int j = 0;
        int result = 0;
        for (; i < vpos.size(); ++i) {
            while (vpos[j] < startPos && k < 2*(startPos-vpos[j])+vpos[i]-startPos) {
                ++j;
            }
            if (vpos[j] < startPos) {
                result = max(result, vsum[i]-((j-1>=0)?vsum[j-1]:0));
            } else if (vpos[i] - startPos <= k) {
                result = max(result, vsum[i]-((j-1>=0)?vsum[j-1]:0));
            } else {
                break;
            }
        }
        i = start-1;
        j = vpos.size()-1;
        for (; i >= 0; --i) {
            while (vpos[j] > startPos && k < 2*(vpos[j]-startPos)+startPos-vpos[i]) {
                --j;
            }
            if (vpos[j] > startPos) {
                result = max(result, vsum[j]-((i-1>=0)?vsum[i-1]:0));
            } else if (startPos - vpos[i] <= k) {
                result = max(result, vsum[j]-((i-1>=0)?vsum[i-1]:0));
            } else {
                break;
            }
        }
        return result;
    }
};
