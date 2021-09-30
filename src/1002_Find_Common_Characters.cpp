class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> counts(26, INT_MAX);
        for (auto a:A) {
            vector<int> temp(26, 0);
            for (auto c:a) {
                ++temp[c-'a'];
            }
            for (int i = 0; i < 26; ++i) {
                counts[i] = min(counts[i], temp[i]);
            }
        }
        vector<string> result;
        for (int i = 0; i < counts.size(); ++i) {
            for (int j = 0; j < counts[i]; ++j) {
                string s(1, 'a'+i);
                result.push_back(s);
            }
        }
        return result;
    }
};
