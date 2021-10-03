class Solution {
public:
    int minTimeToType(string word) {
        char c = 'a';
        int result = 0;
        for (int i = 0; i < word.size(); ++i) {
            int temp = abs(word[i]-c);
            if (c < word[i]) {
                temp = min(temp, c+26-word[i]);
            } else {
                temp = min(temp, word[i]+26-c);
            }
            result += temp;
            c = word[i];
            ++result;
        }
        return result;
    }
};
