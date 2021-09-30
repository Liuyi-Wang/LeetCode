class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = 0;
        int result = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i-1]-A[i] == A[i-2]-A[i-1]) {
                ++len;
                result += len;
            } else {
                len = 0;
            }
        }
        return result;
    }
};
