class Solution {
public:
    int removePalindromeSub(string s) {
        if (0 == s.size()) {
            return 0;
        }
        string r = s;
        reverse(s.begin(), s.end());
        if (s == r) {
            return 1;
        }
        return 2;
    }
};
