class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> os(S.size(), 0);
        vector<int> zs(S.size(), 0);
        int count = 0;
        for (int i = 0; i < S.size(); ++i) {
            if ('1' == S[i]) {
                ++count;
            }    
            os[i] = count;
        }
        count = 0;
        for (int i = S.size()-1; i >= 0; --i) {
            if ('0' == S[i]) {
                ++count;
            }    
            zs[i] = count;
        }
        int result = INT_MAX;
        for (int i = 0; i < S.size(); ++i) {
            result = min(result, os[i]+zs[i]-1);
        }
        return result;
    }
};
