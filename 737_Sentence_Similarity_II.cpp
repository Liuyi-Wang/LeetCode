static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string f(string s) {
        string r = s;
        while (r != d_r[r]) {
            r = d_r[r];
        }
        while (r != d_r[s]) {
            string t = s;
            d_r[s] = r;
            s = t;
        }
        return r;
    }
    
    void u(const string &a, const string &b) {
        string ar = f(a);
        string br = f(b);
        if (ar != br) {
            d_r[ar] = br;
        }   
    }
    
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        for (const auto p:pairs) {
            d_r[p[0]] = p[0];
            d_r[p[1]] = p[1];
        }
        for (const auto p:pairs) {
            u(p[0], p[1]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i] || f(words1[i]) == f(words2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
    
private:
    unordered_map<string, string> d_r;    
};
