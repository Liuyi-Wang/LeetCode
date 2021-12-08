class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int low = pow(10, (left.size()/2)/2);
        int high = pow(10, (right.size()/2)/2+1);
        unsigned long long l = stoull(left);
        unsigned long long r = stoull(right);
        int result = 0;
        for (int i = low; i <= high; ++i) {
            unsigned long long p = superpalindrome(i, true);
            unsigned long long sp = p*p;
            if (valid(sp, l, r)) {
                ++result;
            }
            p = superpalindrome(i, false);
            sp = p*p;
            if (valid(sp, l, r)) {
                ++result;
            }
        }
        return result;
    }
    
    unsigned long long superpalindrome(unsigned long long n, bool flag) {
        unsigned long long r = 0;
        int count = 0;
        unsigned long long m = n;
        while (m > 0) {
            r = r*10+m%10;
            m /= 10;
            ++count;
        }
        if (flag) {
            n /= 10;
        }
        return n*pow(10, count)+r;
    }
    
    bool valid(unsigned long long sp, unsigned long long l, unsigned long long r) {
        if (sp < l || sp > r) {
            return false;
        }
        string s = to_string(sp);
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
