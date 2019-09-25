class Solution {
public:
    bool less(const string& s1, const string& s2, const vector<int>& v) {
        int i1 = 0, i2 = 0;
        while (i1 < s1.size() && i2 < s2.size()) {
            if (v[s1[i1]-'a'] < v[s2[i2]-'a']) {
                return true;
            }
            if (v[s1[i1]-'a'] > v[s2[i2]-'a']) {
                return false;
            }
            ++i1;
            ++i2;
        }
        return s1.size() < s2.size();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26, 0);
        for (int i = 0; i < 26; ++i) {
            v[order[i]-'a'] = i;
        }
        for (int i = 0; i < words.size()-1; ++i) {
            if (!less(words[i], words[i+1], v)) {
                return false;
            }
        }
        return true;
    }
};
