class Solution {
public:
    int freq(const string& s) {
        char c = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (c == s[i]) {
                ++count;
            } else if (c > s[i]) {
                c = s[i];
                count = 1;
            }
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsFreq(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            wordsFreq[i] = freq(words[i]);
        }
        sort(wordsFreq.begin(), wordsFreq.end());
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int count = freq(queries[i]);
            vector<int>::iterator it = upper_bound(wordsFreq.begin(), wordsFreq.end(), count);
            result[i] = wordsFreq.size() - (it-wordsFreq.begin());
        }
        return result;
    }
};
