class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        int result = 0;
        for (int i = 0; i < words.size()-1; ++i) {
            if (words[i] != words[i+1].substr(0, words[i].size())) {
                result += words[i].size()+1;
            }
        }
        result += words.back().size()+1;
        return result;
    }
};
