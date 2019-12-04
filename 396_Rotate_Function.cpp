class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long n = A.size();
        long sum = 0;
        long f = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            f += A[i]*i;
        }
        long result = f;
        for (int i = 1; i < n; ++i) {
            f += sum-n*A[n-i];
            result = max(result, f);
        }
        return result;
    }
};
