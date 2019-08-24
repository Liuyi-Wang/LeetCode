class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1, even = 0;
        while (odd < A.size() && even < A.size()) {
            if (1 == A[odd]%2) {
                odd += 2;
                continue;
            }
            if (0 == A[even]%2) {
                even += 2;
                continue;
            }
            swap(A[odd], A[even]);
        }
        return A;
    }
};
