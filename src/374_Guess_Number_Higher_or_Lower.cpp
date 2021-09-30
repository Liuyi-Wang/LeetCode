// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n;
        while (l+1 < r) {
            long m = l+(r-l)/2;
            int ans = guess(m);
            if (0 == ans) {
                return m;
            } else if (-1 == ans) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (0 == guess(l)) {
            return l;
        }
        return r;
    }
};
