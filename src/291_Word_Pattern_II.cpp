static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(const string &p, int pi, const string &s, int si) {
        if (pi == p.size() && si == s.size()) {
            return true;
        }
        if (pi == p.size() || si == s.size()) {
            return false;
        }
        if (cs.find(p[pi]) == cs.end()) {
            for (int i = si; i < s.size(); ++i) {
                if (pt.find(s.substr(si, i-si+1)) != pt.end()) {
                    continue;
                }
                cs[p[pi]] = s.substr(si, i-si+1);
                pt.insert(s.substr(si, i-si+1));
                if (solve(p, pi+1, s, i+1)) {
                    return true;
                }
                cs.erase(cs.find(p[pi]));
                pt.erase(pt.find(s.substr(si, i-si+1)));
            }
        } else {
            string str = cs[p[pi]];
            if (str != s.substr(si, str.size())) {
                return false;
            }
            return solve(p, pi+1, s, si+str.size());
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        bool result = solve(pattern, 0, str, 0);
        /*
        for (unordered_map<char, string>::iterator it = d_hash.begin(); it != d_hash.end(); ++it) {
            cout << it->first << "=" << it->second << endl;
        }*/
        return result;
    }
    
private:
    unordered_map<char, string> cs;
    unordered_set<string> pt;
};
