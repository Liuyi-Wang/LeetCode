static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        for (auto c:s) {
            if ('A' == c) {
                ++a;
                if (a > 1) {
                    return false;
                }
                l = 0;
            } else if ('L' == c) {
                ++l;
                if (l > 2) {
                    return false;
                }
            } else {
                l = 0;
            }
        }
        return true;
    }
};
