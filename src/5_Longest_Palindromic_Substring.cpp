static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        bool dp[s.size()][s.size()] = { {false} };
        int begin = 0, l = 0;
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i < s.size()+1-len; ++i) {
                int j = i+len-1;
                if ((1 == len) || (2 == len && s[i] == s[j]) || (s[i] == s[j] && dp[i+1][j-1])) {
                    dp[i][j] = true;
                    begin = i;
                    l = len;
                    continue;
                }   
            }
        }
        return s.substr(begin, l);
    }
};
