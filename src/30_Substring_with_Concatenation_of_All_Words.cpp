static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (0 == s.size() || 0 == words.size()) {
            return vector<int>();
        }
        unordered_map<string, int> dict;
        for (const auto& w:words) {
            ++dict[w];
        }
        int step = words[0].size();
        vector<int> result;
        for (int i = 0; i < s.size()+1-step*words.size(); ++i) {
            unordered_map<string, int> count;
            bool valid = true;
            for (int j = i; j < i+step*words.size(); j += step) {
                string t = s.substr(j, step);
                if (dict.find(t) == dict.end()) {
                    valid = false;
                    break;
                }
                ++count[t];
                if (count[t] > dict[t]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(i);
            }
        }
        return result;
    }
};
