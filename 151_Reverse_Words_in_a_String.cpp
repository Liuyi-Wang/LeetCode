class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0;
        int index = 0;
        while (true) {
            while (l < s.size() && ' ' == s[l]) {
                ++l;
            }
            if (l == s.size()) {
                break;
            }
            r = l;
            while (r < s.size() && ' ' != s[r]) {
                ++r;
            }
            reverse(s.begin()+l, s.begin()+r);
            for (int i = l; i < r; ++i) {
                s[index++] = s[i];
            }
            if (index < s.size()) {
                s[index++] = ' ';
            }
            l = r;
        }
        if (' ' == s[index-1]) {
            return s.substr(0, index-1);
        }
        return s.substr(0, index);
    }
};
