static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counts(26, 0);
        int count = 0;
        for (auto c:ransomNote) {
            ++counts[c-'a'];
            if (1 == counts[c-'a']) {
                ++count;
            }
        }
        for (auto c:magazine) {
            --counts[c-'a'];
            if (0 == counts[c-'a']) {
                --count;
            }
        }
        return 0 == count;
    }
};
