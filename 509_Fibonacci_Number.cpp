static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int fib(int N) {
        if (0 == N) {
            return 0;
        }
        if (1 == N) {
            return 1;
        }
        int n1 = 0, n2 = 1;
        int result;
        for (int i = 2; i <= N; ++i) {
            result = n1+n2;
            n1 = n2;
            n2 = result;
        }
        return result;
    }
};
