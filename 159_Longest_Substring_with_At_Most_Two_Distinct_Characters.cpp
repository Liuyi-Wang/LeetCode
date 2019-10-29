static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (0 == s.size()) {
            return 0;
        }
        char c1, c2;
        unordered_map<char, int> dict;
        c1 = s[0];
        dict[c1] = 0;
        int index = 1;
        for (; index < s.size(); ++index) {
            if (s[index] != s[index-1]) {
                c2 = s[index];
                dict[c2] = index;
                break;
            } else {
                dict[c1] = index;
            }
        }
        int result = 0;
        int begin = 0;
        for (; index < s.size(); ++index) {
            if (s[index] != c1 && s[index] != c2) {
                result = max(result, index-begin);
                char out;
                if (s[index-1] == c1) {
                    out = c2;
                    c2 = s[index];
                } else {
                    out = c1;
                    c1 = s[index];
                }
                begin = dict[out]+1;
            }
            dict[s[index]] = index;
        }
        return max(result, index-begin);
    }
};
