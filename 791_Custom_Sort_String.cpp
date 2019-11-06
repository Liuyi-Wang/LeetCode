class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> d_i;
        for (int i = 0; i < S.size(); ++i) {
            d_i[S[i]] = i;
        }
        sort(T.begin(), T.end(), [&](const char &c1, const char &c2) {
            return d_i[c1] < d_i[c2];    
        });
        return T;
    }
};
