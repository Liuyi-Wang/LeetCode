class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result(A.size(), 0);
        int begin = 0, end = A.size()-1;
        int i = A.size()-1;
        while (begin <= end) {
            if (abs(A[begin]) > abs(A[end])) {
                result[i--] = A[begin]*A[begin];
                ++begin;
            } else {
                result[i--] = A[end]*A[end];
                --end;;
            }
        }
        return result;
    }
};
