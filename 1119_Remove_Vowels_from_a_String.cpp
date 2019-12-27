static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string removeVowels(string S) {
        string result;
        for (auto c:S) {
            if ('a' != c && 'e' != c && 'i' != c && 'o' != c && 'u' != c) {
                result += c;
            }
        }
        return result;
    }
};
