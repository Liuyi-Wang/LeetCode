/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0;
        int result = 0;
        for (auto croak:croakOfFrogs) {
            if (croak == 'c') {
                ++c;
            } else if (croak == 'r') {
                ++r;
                if (r > c) {
                    return -1;
                }
            } else if (croak == 'o') {
                ++o;
                if (o > c) {
                    return -1;
                }
                if (o > r) {
                    return -1;
                }
            } else if (croak == 'a') {
                ++a;
                if (a > c) {
                    return -1;
                }
                if (a > r) {
                    return -1;
                }
                if (a > o) {
                    return -1;
                }
            } else if (croak == 'k') {
                --c;
                --r;
                --o;
                --a;
            }
            result = max(result, c);
        }
        if (c != 0) {
            return -1;
        }
        return result;
    }
};
