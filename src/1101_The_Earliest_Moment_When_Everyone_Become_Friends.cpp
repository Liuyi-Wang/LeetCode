/**
 *  Time:
 *  O(mlogm + n + m)
 *  Space:
 *  O(n)
 */
class Solution {
    vector<int> d_r;
    int n;
    int count;
    
    int f(int a) {
        int r = a;
        while (r != d_r[r]) {
            r = d_r[r];
        }
        while (d_r[a] != r) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void u(int a, int b) {
        int ra = f(a);
        int rb = f(b);
        if (ra > rb) {
            d_r[ra] = rb;
            --count;
        } else if (ra < rb) {
            d_r[rb] = ra;
            --count;
        }
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        this->n = n;
        count = n;
        d_r = vector<int>(n, 0);
        for (int i = 1; i < n; ++i) {
            d_r[i] = i;
        }
        for (auto log:logs) {
            u(log[1], log[2]);
            if (count == 1) {
                return log[0];
            }
        }
        return -1;
    }
};
