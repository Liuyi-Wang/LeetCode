static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isUgly(int num) {
        while (num > 1) {
            if (0 == num%2) {
                num /= 2;
            } else if (0 == num%3) {
                num /= 3;
            } else if (0 == num%5) {
                num /= 5;
            } else {
                return false;
            }
        }
        return num == 1;
    }
};
