class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int begin = 0, end = A.size()-1;
        while (begin < end) {
            if (1 == A[begin]%2 && 0 == A[end]%2) {
                swap(A[begin], A[end]);
            }
            while (begin < A.size() && 0 == A[begin]%2) {
                ++begin;
            }
            while (end >= 0 && 1 == A[end]%2) {
                --end;
            }
        }
        return A;
    }
};
