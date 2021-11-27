typedef long long ll;
class Solution {
    ll high;
    ll low;
public:
    int largestPalindrome(int n) {
        this->high = pow(10, n)-1;
        this->low = pow(10, n-1);
        for (ll i = high; i >= low; --i) {
            ll p = constructPalindrome(i, false);
            if (valid(p)) {
                return p%1337;
            }
        }
        for (ll i = high; i >= low; --i) {
            ll p = constructPalindrome(i, true);
            if (valid(p)) {
                return p%1337;
            }
        }
        return -1;
    }
    
    ll constructPalindrome(ll n, bool flag) {
        ll r = 0;
        ll m = n;
        int count = 0;
        while (m) {
            r = r*10+(m%10);
            m /= 10;
            ++count;
        }
        if (flag) {
            n /= 10;
        }
        n *= pow(10, count);
        return n+r;
    }
    
    bool valid(ll p) {
        for (ll i = high; i >= sqrt(p); --i) {
            if (p%i == 0 && p/i >= low) {
                return true;
            }
        }
        return false;
    }
};
