static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto m:moves) {
            if ('U' == m) {
                y += 1;
            } else if ('R' == m) {
                x += 1;
            } else if ('D' == m) {
                y -= 1;
            } else if ('L' == m) {
                x -= 1;
            }
        }
        return x == 0 && y == 0;
    }
};
