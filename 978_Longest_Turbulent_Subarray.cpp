class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int result = 1;
        int begin = 0;
        int sign = 0;
        A.push_back(A.back());
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i-1]) {
                result = max(result, i-begin);
                sign = 0;
                begin = i;
            } else {
                if (sign == 0) {
                    sign = (A[i-1]>A[i])?1:(-1);
                    begin = i-1;
                } else {
                    int current = (A[i-1]>A[i])?1:(-1);
                    if (sign == current) {
                        result = max(result, i-begin);
                        begin = i-1;
                    } else {
                        sign = current;
                    }
                }
            }
        }
        return result;
    }
};
