class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> counts1;
        int result = 0;
        for (auto word:words1) {
            ++counts1[word];
        }
        unordered_map<string, int> counts2;
        for (auto word:words2) {
            ++counts2[word];
            if (counts2[word] == 1 && counts1[word] == 1) {
                ++result;
            } else if (counts2[word] == 2 && counts1[word] == 1) {
                --result;
            }
        }
        return result;
    }
};
