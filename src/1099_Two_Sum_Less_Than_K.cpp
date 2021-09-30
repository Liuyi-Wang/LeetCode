class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l = 0, r = A.size()-1;
        int result = -1;
        while (l < r) {
            int sum = A[l]+A[r];
            if (sum < K) {
                result = max(result, sum);
                ++l;
            } else {
                --r;    
            }
        }
        return result;
    }
};
