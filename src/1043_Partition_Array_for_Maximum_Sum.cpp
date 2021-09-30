class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> sums(A.size(), 0);
        int m = 0;
        for (int i = 0; i < K; ++i) {
            m = max(m, A[i]);
            sums[i] = m*(i+1);
        }
        for (int i = K; i < A.size(); ++i) {
            m = 0;
            for (int j = 0; j < K; ++j) {
                m = max(m, A[i-j]);
                sums[i] = max(sums[i], m*(j+1)+sums[i-j-1]);
            }
        }
        return sums.back();
    }
};
