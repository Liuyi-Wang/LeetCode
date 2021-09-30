static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 1;
        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++cur;
            } else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) {
                ++result;
            }
        }
        return result;
    } 
};
