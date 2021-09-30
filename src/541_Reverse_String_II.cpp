static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            int end = min(int(s.size()), i+k);
            reverse(s.begin()+i, s.begin()+end);
            i += 2*k;
        }
        return s;
    }
};
