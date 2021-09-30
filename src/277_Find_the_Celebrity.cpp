static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int c = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(c, i)) {
                c = i;
            }
        }
        for (int i = 0; i < c; ++i) {
            if (!knows(i, c) || knows(c, i)) {
                return -1;
            }
        }
        for (int i = c+1; i < n; ++i) {
            if (!knows(i, c)) {
                return -1;
            }
        }
        return c;
    }
};
