static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            d_times[sentences[i]] = times[i];
            for (int j = 1; j <= sentences[i].size(); ++j) {
                d_trie[sentences[i].substr(0, j)].push_back(sentences[i]);
            }
        }
    }
    
    void add() {
        if (d_times.find(s) != d_times.end()) {
            ++d_times[s];
            return;
        }
        d_times[s] = 1;
        for (int j = 1; j <= s.size(); ++j) {
            d_trie[s.substr(0, j)].push_back(s);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            add();
            s = "";
            return {};
        }
        s += c;
        auto sortRuleLambda = [&] (string s1, string s2) -> bool {
            if (d_times[s1] == d_times[s2]) {
                return s1 < s2;
            }
            return d_times[s1] > d_times[s2];
        };
        sort(d_trie[s].begin(), d_trie[s].end(), sortRuleLambda);
        vector<string> result;
        for (int i = 0; i < 3 && i < d_trie[s].size(); ++i) {
            result.push_back(d_trie[s][i]);
        }
        return result;
    }
    
private:
    unordered_map<string, vector<string>> d_trie;
    unordered_map<string, int> d_times;
    string s;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
