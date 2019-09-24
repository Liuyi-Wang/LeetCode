class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = 0;
        for (auto s:S) {
            if ('-' != s) {
                ++count;
            }
        }
        string result((count-1)/K+1-1+count, 'a');
        int s = S.size()-1, r = result.size()-1;
        count = 0;
        while (s >= 0 && r >= 0) {
            if (0 != count && 0 == count%K) {
                result[r--] = '-';
                count = 0;
                continue;
            }
            if ('-' != S[s]) {
                result[r--] = toupper(S[s--]);
                ++count;
            } else {
                s--;
            }
        }
        return result;
    }
};
