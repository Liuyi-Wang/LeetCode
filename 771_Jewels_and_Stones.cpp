static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for (auto c:J) {
            s.insert(c);
        }
        int result = 0;
        for (auto c:S) {
            if (s.find(c) != s.end()) {
                ++result;
            }
        }
        return result;
    }
};
