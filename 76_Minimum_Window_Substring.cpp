static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for (auto c:t) {
            ++dict[c];
        }
        int begin = 0, len = INT_MAX, count = 0, result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (--dict[s[i]] >= 0) {
                ++count;
            }
            while (count == t.size()) {
                if (len > i-begin+1) {
                    len = i-begin+1;
                    result = begin;
                }
                if (++dict[s[begin]] >= 1) {
                    --count;
                } 
                ++begin;
            }
        }
        return len==INT_MAX?"":s.substr(result, len);
    }
};
