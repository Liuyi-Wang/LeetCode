class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (0 == S) {
            int result = 0;
            int len = 0;
            for (const auto a:A) {
                if (1 == a) {
                    result += (len+1)*len/2;
                    len = 0;
                } else {
                    ++len;
                }
            }
            result += (len+1)*len/2;
            return result;
        }
        int begin = 0, end = 0, sum = A[0], result = 0;
        while (begin <= end && end < A.size()) {
            if (S == sum) {
                int bc = 1;
                while (0 == A[begin]) {
                    ++bc;
                    ++begin;
                }
                int ec = 1;
                ++end;
                while (end < A.size() && 0 == A[end]) {
                    ++ec;
                    ++end;
                }
                if (end != A.size()) {
                    ++sum;
                }
                result += bc*ec;
                continue;
            }
            while (S > sum) {
                ++end;
                if (A.size() == end) {
                    break;
                }
                sum += A[end];
            }
            while (S < sum && begin < end) {
                sum -= A[begin];
                ++begin;
            }
        }
        return result;
    }
};
