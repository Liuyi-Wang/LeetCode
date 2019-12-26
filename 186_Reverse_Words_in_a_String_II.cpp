static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0;
        int index = 0;
        while (true) {
            while (l < s.size() && ' ' == s[l]) {
                ++l;
            }
            if (l == s.size()) {
                break;
            }
            r = l;
            while (r < s.size() && ' ' != s[r]) {
                ++r;
            }
            reverse(s.begin()+l, s.begin()+r);
            for (int i = l; i < r; ++i) {
                s[index++] = s[i];
            }
            if (index < s.size()) {
                s[index++] = ' ';
            }
            l = r;
        }
    }
};
