class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int> &v1,
                                const vector<int> &v2) {
            return v1[0] < v2[0];
        }    
    };
    
    int f(int n) {
        int r = n;
        while (r != d_r[r]) {
            r = d_r[r];
        }
        while (r != d_r[n]) {
            int t = d_r[n];
            d_r[n] = r;
            d_c[n] = 0;
            n = t;
        }
        return r;
    }
    
    void u(int a, int b) {
        int ar = f(a);
        int br = f(b);
        if (ar != br) {
            d_r[ar] = br;
            d_c[br] += d_c[ar];
        }
    }
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        d_r = vector<int>(N, 0);
        d_c = vector<int>(N, 1);
        for (int i = 1; i < N; ++i) {
            d_r[i] = i;
        }
        sort(logs.begin(), logs.end(), less_than());
        for (const auto& l:logs) {
            u(l[1], l[2]);
            if (N == d_c[f(l[2])]) {
                return l[0];
            }    
        }
        return -1;
    }
    
private:
    vector<int> d_r;
    vector<int> d_c;
};
