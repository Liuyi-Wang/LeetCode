class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        vector<string> v;
        string s;
        while (ss >> s) {
            v.push_back(s);
        }
        if (pattern.size() != v.size()) {
            return false;
        }
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        for (int i = 0; i < pattern.size(); ++i) {
            if (ps.find(pattern[i]) == ps.end()) {
                ps[pattern[i]] = v[i];
            } else if (ps[pattern[i]] != v[i]) {
                return false;
            }
            if (sp.find(v[i]) == sp.end()) {
                sp[v[i]] = pattern[i];
            } else if (sp[v[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};
