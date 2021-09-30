class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> dict;
        for (const auto& p:pairs) {
            dict[p[0]].insert(p[1]);
            dict[p[1]].insert(p[0]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i] || dict[words1[i]].find(words2[i]) != dict[words1[i]].end()) {
                continue;
            }
            return false;
        }
        return true;
    }
};
