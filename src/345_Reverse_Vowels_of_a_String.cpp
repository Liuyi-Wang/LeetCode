class Solution {
public:
    bool isVowel(char c) {
        if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c ||
            'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c) {
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                ++l;
            }
            while (l < r && !isVowel(s[r])) {
                --r;
            }
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
