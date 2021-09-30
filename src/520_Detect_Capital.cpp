static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (isupper(word[i])) {
                ++count;
            }   
        }
        if (word.size() == count || 0 == count) {
            return true;
        }
        if (1 != count) {
            return false;
        }
        return isupper(word[0]);
    }
};
