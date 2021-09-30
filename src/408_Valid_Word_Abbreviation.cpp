static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index = 0, i = 0;
        for (; i < abbr.size() && index < word.size();) {
            if (!isdigit(abbr[i])) {
                if (word[index++] != abbr[i++]) {
                    return false;
                }
                continue;
            }
            if ('0' == abbr[i]) {
                return false;
            }
            int l = i;
            while (i < abbr.size() && isdigit(abbr[i])) {
                ++i;
            }
            int k = atoi(abbr.substr(l, i-l).c_str());
            index += k;
        }
        return i == abbr.size() && index == word.size();
    }
};
