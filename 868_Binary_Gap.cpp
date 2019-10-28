static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int binaryGap(int N) {
        int result = 0;
        int last = -1;
        int index = 0;
        while (0 != N) {
            int i = 1&N;
            N = N >> 1;
            if (1 == i && -1 == last) {
                last = index;
            } else if (1 == i) {
                result = max(result, index-last);
                last = index;
            }
            ++index;
        }
        return result;   
    }
};
