class Solution {
public:
    bool solve(const string &S, const string &w) {
        int si = 0, wi = 0;
        while (si < S.size() && wi < w.size()) {
            if (S[si] != w[wi]) {
                return false;
            }
            int sc = 1;
            ++si;
            while (si < S.size() && S[si] == S[si-1]) {
                ++sc;
                ++si;
            }
            int wc = 1;
            ++wi;
            while (wi < w.size() && w[wi] == w[wi-1]) {
                ++wc;
                ++wi;
            }
            if (wc > sc) {
                return false;
            }
            if (wc == sc) {
                continue;
            }
            if (sc < 3) {
                return false;
            }
        }
        if (si != S.size() || wi != w.size()) {
            return false;
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int result = 0;
        for (const auto &w:words) {
            if (solve(S, w)) {
                ++result;
            }
        }
        return result;
    }
};
