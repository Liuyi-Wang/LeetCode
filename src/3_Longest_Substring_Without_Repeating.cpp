static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0, result = 0;
        vector<int> dict(256, -1);
        while (end < s.size()) {
            if (-1 == dict[s[end]] || dict[s[end]] < begin) {
                dict[s[end++]] = end;
                continue;
            }
            result = max(result, end-begin);
            begin = dict[s[end]]+1;
            dict[s[end++]] = end;
        }
        return max(result, end-begin);
    }
};
