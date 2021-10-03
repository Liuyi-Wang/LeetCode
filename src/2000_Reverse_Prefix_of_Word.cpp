class Solution {
public:
    string reversePrefix(string word, char ch) {
        string result;
        int i = 0;
        for (; i < word.size(); ++i) {
            if (word[i] == ch) {
                break;
            }
        }
        if (i == word.size()) {
            return word;
        }
        for (int j = i; j >= 0; --j) {
            result += word[j];
        }
        result += word.substr(i+1);
        return result;
    }
};
