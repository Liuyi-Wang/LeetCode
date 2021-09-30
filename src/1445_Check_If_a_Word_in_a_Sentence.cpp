class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string s;
        int i = 1;
        while (ss >> s) {
            if (searchWord.size() <= s.size() && searchWord == s.substr(0, searchWord.size())) {
                return i;
            }
            ++i;
        }
        return -1;
    }
};
