class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i) {
            if (!dec && !inc) {
                return false;
            }
            if (A[i-1] < A[i]) {
                dec = false;
            }
            if (A[i-1] > A[i]) {
                inc = false;
            }
        }
        if (!dec && !inc) {
            return false;
        }
        return true;
    }
};
