static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        for (; r < s.size(); ++r) {
            if (' ' == s[r]) {
                reverse(s.begin()+l, s.begin()+r);
                l = r+1;
            }
        }
        reverse(s.begin()+l, s.end());
        return s;
    }
};
