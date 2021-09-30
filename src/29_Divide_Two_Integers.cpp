static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == dividend) {
            return 0;
        }
        if (1 == divisor) {
            return dividend;
        }
        if (-1 == divisor && INT_MIN == dividend) {
            return INT_MAX;
        }
        if (-1 == divisor && INT_MAX == dividend) {
            return INT_MIN;
        }
        if (-1 == divisor) {
            return -dividend;
        }
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || 
            (dividend > 0 && divisor < 0)) {
            sign = -1;
        }
        long dend = labs(dividend);
        long sor = labs(divisor);
        int result = 0;
        while (dend >= sor) {
            int b = 1;
            long t = sor;
            while (dend >= t<<b) {
                ++b;
            }
            result += 1<<(b-1);
            dend -= t<<(b-1);
        }
        return sign*result;
    }
};
