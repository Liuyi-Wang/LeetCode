static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        for (auto c:s) {
            ++count[c-'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (1 == count[s[i]-'a']) {
                return i;
            }
        }
        return -1;
    }
};
