static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (0 == p.size()) {
            return 0;
        }
        vector<int> lens(26, 0);
        int len = 1;
        lens[p[0]-'a'] = 1;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == p[i-1]+1 || p[i] == p[i-1]-25) {
                ++len;
            } else {
                len = 1;
            }
            lens[p[i]-'a'] = max(lens[p[i]-'a'], len);
        }
        int result = 0;
        for (auto l:lens) {
            result += l;
        }
        return result;
    }
};
