/**
 *  Time:
 *  O(logn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l+(r-l)/2+1;
            if (valid(mid, n)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
    
    bool valid(long long mid, int n) {
        return (1+mid)*mid/2 <= n;
    }
};
