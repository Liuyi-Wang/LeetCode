static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto &word:dictionary) {
            if (word.size() <= 2) {
                d_hash[word].insert(word);
            } else {
                string ab;
                ab += word[0];
                ab += to_string(word.size()-2);
                ab += word.back();
                d_hash[ab].insert(word);
            }
        }
    }
    
    bool isUnique(string word) {
        if (word.size() <= 2) {
            return d_hash.find(word) == d_hash.end() || (d_hash[word].find(word) != d_hash[word].end() && 1 == d_hash[word].size());
        } else {
            string ab;
            ab += word[0];
            ab += to_string(word.size()-2);
            ab += word.back();
            return d_hash.find(ab) == d_hash.end() || (d_hash[ab].find(word) != d_hash[ab].end() && 1 == d_hash[ab].size());
        }
    }
    
private:
    unordered_map<string, unordered_set<string>> d_hash;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
