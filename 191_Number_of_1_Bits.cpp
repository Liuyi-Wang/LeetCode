static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (0 != n) {
            ++count;
            n = n&(n-1);
        }
        return count;
    }
};
