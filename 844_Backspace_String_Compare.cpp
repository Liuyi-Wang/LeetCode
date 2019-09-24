class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int is = -1, it = -1;
        for (int i = 0; i < S.size(); ++i) {
            if ('#' == S[i] && -1 != is) {
                --is;
            } else if ('#' == S[i]) {
            } else {
                S[++is] = S[i];
            }
        }
        for (int i = 0; i < T.size(); ++i) {
            if ('#' == T[i] && -1 != it) {
                --it;
            } else if ('#' == T[i]) {
            } else {
                T[++it] = T[i];
            }
        }
        if (-1 == is && -1 == it) {
            return true;
        }
        return S.substr(0, is+1) == T.substr(0, it+1);
    }
};
