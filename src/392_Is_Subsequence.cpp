static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int is = 0;
        for (int it = 0; it < t.size(); ++it) {
            if (is == s.size()) {
                break;
            }
            if (s[is] == t[it]) {
                ++is;
            }
        }
        return is == s.size();
    }
};
