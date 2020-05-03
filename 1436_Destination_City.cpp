class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ans;
        unordered_set<string> notans;
        for (const auto &p:paths) {
            notans.insert(p[0]);
            if (ans.find(p[0]) != ans.end()) {
                ans.erase(ans.find(p[0]));
            }
            if (notans.find(p[1]) == notans.end()) {
                ans.insert(p[1]);
            }  
        }
        for (unordered_set<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (notans.find(*it) == notans.end()) {
                return *it;
            }
        }
        return "";
    }
};
