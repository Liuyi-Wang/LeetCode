class Solution {
    int v[50];
public:
    long long kMirror(int k, int n) {
        long long result = 0;
        int len = 1;
        int count = 0;
        while (true) {
            for (long long i = pow(10, len-1); i < pow(10, len); ++i) {
                long long p = constructPalindrome(i, true);
                if (valid(p, k)) {
                    result += p;
                    ++count;
                }
                if (count == n) {
                    return result;
                }
            }
            for (long long i = pow(10, len-1); i < pow(10, len); ++i) {
                long long p = constructPalindrome(i, false);
                if (valid(p, k)) {
                    result += p;
                    ++count;
                }
                if (count == n) {
                    return result;
                }
            }
            ++len;
        }
    }
    
    long long constructPalindrome(long long n, bool flag) {
        long long m = n;
        long long mirror = 0;
        int count = 0;
        while (m) {
            mirror = mirror*10+(m%10);
            m /= 10;
            ++count;
        }
        if (flag) {
            n /= 10;
        }
        return n*pow(10, count)+mirror;
    }
    
    bool valid(long long p, int k) {
        int t = 0;
        while (p) {
            v[t++] = p%k;
            p /= k;
        }
        int l = 0, r = t-1;
        while (l < r) {
            if (v[l++] != v[r--]) {
                return false;
            }
        }
        return true;
    }
};
