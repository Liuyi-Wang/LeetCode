static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result(S.size(), 0);
        int index = 0;
        for (; index < S.size(); ++index) {
            if (C == S[index]) {
                break;
            }
        }
        for (int i = index-1; i >= 0; --i) {
            result[i] = index-i;
        }
        int last = index;
        ++index;
        for (; index < S.size(); ++index) {
            if (C != S[index]) {
                result[index] = index-last;
                continue;
            }
            for (int i = index-1; i > last; --i) {
                if (result[i] <= index-i) {
                    break;
                }
                result[i] = index-i;
            }
            last = index;
        }
        return result;
    }
};
