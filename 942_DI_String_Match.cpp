static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int begin = 0, end = S.size();
        vector<int> result(S.size()+1, 0);
        for (int i = 0; i < S.size(); ++i) {
            if ('I' == S[i]) {
                result[i] = begin++;
            } else {
                result[i] = end--;
            }
        }
        result.back() = begin;
        return result;
    }
};
