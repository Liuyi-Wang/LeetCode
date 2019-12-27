static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countLetters(string S) {
        int l = 1;
        int result = 0;
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == S[i-1]) {
                ++l;
                continue;
            }
            while (l > 0) {
                result += l;
                --l;
            }
            l = 1;
        }
        while (l > 0) {
            result += l;
            --l;
        }
        return result;
    }
};
