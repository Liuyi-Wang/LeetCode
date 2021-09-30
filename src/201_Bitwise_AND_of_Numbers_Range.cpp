static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            ++i;
            m >>= 1;
            n >>= 1;
        }
        return m<<i;
    }
};
