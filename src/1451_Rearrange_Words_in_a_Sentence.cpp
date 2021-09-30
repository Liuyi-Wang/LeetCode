class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> hash;
        text[0] += 32;
        stringstream ss(text);
        string s;
        while (ss >> s) {
            hash[s.size()].push_back(s);
        }
        string result;
        for (map<int, vector<string>>::iterator it = hash.begin(); it != hash.end(); ++it) {
            for (auto word:it->second) {
                result += (word+" ");
            }
        }
        result[0] -= 32;
        result.pop_back();
        return result;
    }
};
