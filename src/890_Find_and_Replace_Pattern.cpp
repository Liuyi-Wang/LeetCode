static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> wp, pw;
        vector<string> result;
        for (const auto& w:words) {
            if (w.size() != pattern.size()) {
                continue;
            }
            wp.clear();
            pw.clear();
            bool valid = true;
            for (int i = 0; i < w.size(); ++i) {
                if (wp.find(w[i]) == wp.end()) {
                    if (pw.find(pattern[i]) == pw.end()) {
                        wp[w[i]] = pattern[i];
                        pw[pattern[i]] = w[i];
                    } else {
                        valid = false;
                        break;
                    }
                } else {
                    if (wp[w[i]] != pattern[i]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                result.push_back(w);
            }
        }
        return result;
    }
};
