static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0, count = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            count = max(count, ++counts[s[i]-'A']);
            while (i-start+1 > count+k) {
                --counts[s[start++]-'A'];
            }
            result = max(result, i-start+1);
        }
        return result;
    }
};
