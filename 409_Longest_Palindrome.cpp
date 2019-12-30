static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for (auto c:s) {
            ++hash[c];
        }
        bool odd = false;
        int result = 0;
        for (unordered_map<char, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
            if (0 == it->second%2) {
                result += it->second;
            } else {
                result += it->second-1;
                odd = true;
            }
        }
        return result + (odd?1:0);
    }
};
