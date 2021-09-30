class Solution {
public:
    int numWays(int n, int k) {
        if (0 == n) {
            return 0;
        }
        if (1 == n) {
            return k;
        }
        int diff = k, same = 0;
        for (int i = 2; i <= n; ++i) {
            int d = diff;
            int s = same;
            diff = (d+s)*(k-1);
            same = d;
        }
        return diff+same;
    }
};
