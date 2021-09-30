class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int result = 0;
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        for (auto n:croakOfFrogs) {
            if ('c' == n) {
                ++c;
                if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                    --c;
                    --r;
                    --o;
                    --a;
                    --k;
                }
                result = max(result, c);
            } else if ('r' == n) {
                ++r;
                if (r > c) {
                    return -1;
                }
                if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                    --c;
                    --r;
                    --o;
                    --a;
                    --k;
                }
                result = max(result, r);
            } else if ('o' == n) {
                ++o;
                if (o > r || o > c) {
                    return -1;
                }
                if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                    --c;
                    --r;
                    --o;
                    --a;
                    --k;
                }
                result = max(result, o);
            } else if ('a' == n) {
                ++a;
                if (a > o || a > r || a > c) {
                    return -1;
                }
                if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                    --c;
                    --r;
                    --o;
                    --a;
                    --k;
                }
                result = max(result, a);
            } else if ('k' == n) {
                ++k;
                if (k > a || k > o || k > r || k > c) {
                    return -1;
                }
                if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                    --c;
                    --r;
                    --o;
                    --a;
                    --k;
                }
                result = max(result, k);
            }
        }
        if (c > 0 || r > 0 || o > 0 || a > 0 || k > 0) {
            return -1;
        }
        return result;
    }
};
