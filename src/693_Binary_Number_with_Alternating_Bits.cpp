static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long m = n;
        return ((m + (m >> 1) + 1) & (m + (m >> 1))) == 0;
    }
};
