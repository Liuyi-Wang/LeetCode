/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int dpc = 0, dpr = 0, dpo = 0, dpa = 0, dpk = 0;
        int result = 0;
        for (auto c:croakOfFrogs) {
            if (c == 'c') {
                ++dpc;
                result = max(result, dpc);
            }
            if (c == 'r') {
                ++dpr;
                if (dpr > dpc) {
                    return -1;
                }
            }
            if (c == 'o') {
                ++dpo;
                if (dpo > dpr) {
                    return -1;
                }
            }
            if (c == 'a') {
                ++dpa;
                if (dpa > dpo) {
                    return -1;
                }
            }
            if (c == 'k') {
                ++dpk;
                if (dpk > dpa) {
                    return -1;
                }
                --dpc;
                --dpr;
                --dpo;
                --dpa;
                --dpk;
            }
        }
        if (dpc != 0) {
            return -1;
        }
        return result;
    }
};
