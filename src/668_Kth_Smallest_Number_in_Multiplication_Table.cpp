/**
 *  Time:
 *  O(log(m*n)*m)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while (l < r) {
            int mid = l+(r-l)/2;
            int K = smallerEqual(mid, m, n);
            if (k > K) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    
    int smallerEqual(int num, int m, int n) {
        int k = 0;
        for (int i = 1; i <= m; ++i) {
            k += min(n, num/i);
        }
        return k;
    }
};
