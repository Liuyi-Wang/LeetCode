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
    
    int find(int a) {
        int r = a;
        while (d_r[r] != r) {
            r = d_r[r];
        }
        while (d_r[a] != r) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra != rb) {
            d_r[ra] = rb;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        vector<int> primes = sieve(sqrt(100000));
        d_r = vector<int>(100001, 0);
        for (int i = 1; i < d_r.size(); ++i) {
            d_r[i] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (int j = 0; j < primes.size(); ++j) {
                if (num < primes[j]) {
                    break;
                }
                if (num%primes[j] == 0) {
                    merge(nums[i], primes[j]);
                }
                while (num%primes[j] == 0) {
                    num /= primes[j];
                }
            }
            if (num != 1) {
                merge(nums[i], num);
            }
        }
        int result = 0;
        unordered_map<int, int> counts;
        for (auto num:nums) {
            ++counts[find(num)];
            result = max(result, counts[find(num)]);
        }
        return result;
    }
    
private:
    vector<int> d_r;
};
