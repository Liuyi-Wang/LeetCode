class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (m == A[m]) {
                r = m;
            } else if (m < A[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (l == A[l]) {
            return l;
        }
        if (r == A[r]) {
            return r;
        }
        return -1;
    }
};
