class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0;
        int sum = 0;
        int num = INT_MAX;
        for (; i < A.size() && i < K; ++i) {
            num = min(num, abs(A[i]));
            if (A[i] <= 0) {
                sum += -A[i];
            } else {
                break;
            }
        }
        K -= i;
        for (; i < A.size(); ++i) {
            num = min(num, abs(A[i]));
            sum += A[i];
        }
        if (0 == K || 0 == K%2) {
            return sum;
        }
        return sum - num*2;
    }
};
