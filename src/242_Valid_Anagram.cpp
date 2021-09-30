static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;
        int count = 0;
        for (auto c:s) {
            ++counts[c];
            if (1 == counts[c]) {
                ++count;
            }
        }
        for (auto c:t) {
            --counts[c];
            if (counts[c] < 0) {
                return false;
            } else if (0 == counts[c]) {
                --count;
            }
        }
        return 0 == count;
    }
};
