static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isP(const string &s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> indices;
        set<int> lens;
        for (int i = 0; i < words.size(); ++i) {
            indices[words[i]] = i;
            lens.insert(words[i].size());
        }
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            reverse(word.begin(), word.end());
            if (indices.find(word) != indices.end() && indices[word] != i) {
                result.push_back({i, indices[word]});
            }
            set<int>::iterator itend = lens.find(word.size());
            for (set<int>::iterator it = lens.begin(); it != itend; ++it) {
                if (isP(word.substr(*it)) && indices.find(word.substr(0, *it)) != indices.end()) {
                    result.push_back({indices[word.substr(0, *it)], i});
                }
                if (isP(word.substr(0, word.size()-*it)) && indices.find(word.substr(word.size()-*it)) != indices.end()) {
                    result.push_back({i, indices[word.substr(word.size()-*it)]});
                }
            }
        }
        return result;
    }
};
