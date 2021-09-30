class Solution {
public:
    void longestK(vector<int>& v, int K, const vector<int>& A) {
        vector<int> counts(v.size()+1, 0);
        int end = 0;
        int k = 0;
        for (int i = 0; i < v.size(); ++i) {
            while (k <= K && end < v.size()) {
                ++counts[A[end]];
                if (1 == counts[A[end]]) {
                    ++k;
                }
                ++end;
            }
            if (k == K+1) {
                v[i] = end-1;
            }
            --counts[A[i]];
            if (0 == counts[A[i]]) {
                --k;
            }
        }
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> k1(A.size(), A.size());
        vector<int> k(A.size(), A.size());
        longestK(k1, K, A);
        longestK(k, K-1, A);
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            result += k1[i]-k[i];
        }
        return result;
    }
};
