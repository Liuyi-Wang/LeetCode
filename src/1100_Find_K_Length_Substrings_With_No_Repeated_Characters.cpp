static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (S.size() < K) {
            return 0;
        }
        vector<bool> v(26, false);
        int result = 0;
        int l = 0, r = 0;
        while (r < S.size()) {
            while (r < S.size() && r-l < K) {
                if (v[S[r]-'a']) {
                    break;
                }
                v[S[r]-'a'] = true;
                ++r;
            }
            if (r == S.size()) {
                break;
            }
            if (r-l == K) {
                v[S[l++]-'a'] = false;
                ++result;
            } else {
                while (l < r && S[l] != S[r]) {
                    v[S[l++]-'a'] = false;
                }       
                v[S[l++]-'a'] = false;
            }
        }
        if (r-l == K) {
            v[S[l++]-'a'] = false;
            ++result;
        }
        return result;
    }
};
