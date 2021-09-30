static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            d_i[words[i]].push_back(i);    
        }
    }
    
    int shortest(string word1, string word2) {
        int i1 = 0, i2 = 0;
        int result = INT_MAX;
        while (i1 < d_i[word1].size() && i2 < d_i[word2].size()) {
            result = min(result, abs(d_i[word1][i1]-d_i[word2][i2]));
            if (d_i[word1][i1] < d_i[word2][i2]) {
                ++i1;
            } else {
                ++i2;
            }
        }
        return result;
    }
    
private:
    unordered_map<string, vector<int>> d_i;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
