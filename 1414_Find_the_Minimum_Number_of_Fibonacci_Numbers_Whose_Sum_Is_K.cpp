class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> v = {1};
        int next = 1;
        while (next <= k) {
            int t = v.back();
            v.push_back(next);
            next += t; 
        }
        k -= v.back();
        int result = 1;
        int up = v.size()-1;
        while (0 != k) {
            int l = 0, r = up;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (v[m] == k) {
                    return result+1;
                } else if (v[m] > k) {
                    r = m-1;
                } else {
                    l = m;
                }
            }
            if (v[r] == k) {
                return ++result;
            }
            if (v[l] == k) {
                return ++result;
            }
            if (v[r] < k) {
                k -= v[r];
                up = r;
            } else {
                k -= v[l];
                up = l;
            }
            ++result;
        }
        return result;
    }
};
