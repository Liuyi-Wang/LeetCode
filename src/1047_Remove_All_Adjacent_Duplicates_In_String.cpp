class Solution {
public:
    string removeDuplicates(string S) {
        if (S.size() <= 1) {
            return S;
        }
        string result;
        int i = 0;
        for (; i < S.size()-1;) {
            if (result.back() == S[i]) {
                result.pop_back();
                ++i;
                continue;
            }
            if (S[i] == S[i+1]) {
                i += 2;
                continue;
            }
            result += S[i];
            ++i;
        }
        if (i == S.size()) {
           return result;
        }
        if (result.back() == S.back()) {
            result.pop_back();
        } else {
            result += S.back();
        }
        return result;
    }
};
