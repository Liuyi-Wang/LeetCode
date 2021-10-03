class Solution {
public:
    bool halvesAreAlike(string s) {
        int n1 = 0;
        for (int i = 0; i < s.size()/2; ++i) {
            if (isVowel(s[i])) {
                ++n1;
            }
        }
        int n2 = 0;
        for (int i = s.size()/2; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                ++n2;
            }
        }
        return n1 == n2;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};
