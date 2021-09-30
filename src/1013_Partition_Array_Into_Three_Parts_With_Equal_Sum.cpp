class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto i:A) {
            sum += i;
        }
        if (sum%3) {
            return false;
        }
        sum = sum/3;
        int i = 0;
        int p = 0;
        for (; i < A.size(); ++i) {
            p += A[i];
            if (p == sum) {
                ++i;
                break;
            }
        }
        if (A.size() == i) {
            return false;
        }
        p = 0;
        for (; i < A.size(); ++i) {
            p += A[i];
            if (p == sum) {
                ++i;
                break;
            }
        }
        if (A.size() == i) {
            return false;
        }
        return true;
    }
};
