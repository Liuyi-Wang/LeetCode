static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n) {
            return 1;
        }
        double half = myPow(x, n/2);
        if (0 == n%2) {
            return half*half;
        } else if (n > 0) {
            return half*half*x;
        } else {
            return half*half/x;
        }
    }
};
