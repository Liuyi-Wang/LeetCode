class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> valid(n+1, true);
        for (int i = 2; i*i <= n; ++i) {
            if (!valid[i]) {
                continue;
            }
            for (int j = i*i; j <= n; j += i) {
                valid[j] = false;
            }
        }
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (valid[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    
    int f(int a, vector<int>& roots) {
        int r = a;
        while (roots[r] != r) {
            r = roots[r];
        }
        while (roots[a] != r) {
            int t = roots[a];
            roots[a] = r;
            a = t;
        }
        return r;
    }
    
    void u(int a, int b, vector<int>& roots) {
        int ra = f(a, roots);
        int rb = f(b, roots);
        if (ra != rb) {
            roots[ra] = rb;
        }
    }
  
    bool gcdSort(vector<int>& nums) {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        vector<int> primes = sieve(s.back());
        vector<int> roots(s.back()+5, 0);
        for (int i = 0; i < roots.size(); ++i) {
            roots[i] = i;
        }
        for (auto num:nums) {
            int x = num;
            for (auto prime:primes) {
                if (prime > x) {
                    break;
                }
                if (x%prime == 0) {
                    u(x, prime, roots);
                    while (x%prime == 0) {
                        x /= prime;
                    }
                }
                if (x > 1) {
                    u(num, x, roots);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == s[i]) {
                continue;
            }
            if (f(nums[i], roots) != f(s[i], roots)) {
                return false;
            }
        }
        return true;
    }
};
