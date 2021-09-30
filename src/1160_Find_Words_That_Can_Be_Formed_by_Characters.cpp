class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> stats(26, 0);
        for (int i = 0; i < chars.size(); ++i) {
            ++stats[chars[i]-'a'];
        }
        int result = 0;
        for (int i = 0; i < words.size(); ++i) {
            vector<int> counts(26, 0);
            bool good = true;
            for (int j = 0; j < words[i].size(); ++j) {
                if (++counts[words[i][j]-'a'] > stats[words[i][j]-'a']) {
                    good = false;
                    break;
                }
            }
            result += good?words[i].size():0;
        }
        return result;
    }
};
