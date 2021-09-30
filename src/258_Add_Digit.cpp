static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int addDigits(int num) {
        if (0 == num) {
            return 0;
        }
        return (num-1)%9+1;
    }
};
