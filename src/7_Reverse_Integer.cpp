class Solution {
public:
    int reverse(int x) {
        int sign = x>0?1:-1;
        long long X = abs(static_cast<long long>(x));
        long long result = 0;
        while (0 != X) {
            result = result*10 + X%10;
            X /= 10;
        }
        if (result > INT_MAX) {
            return 0;
        }
        return sign*result;
    }
};
