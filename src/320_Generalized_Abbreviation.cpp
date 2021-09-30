static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        result.push_back(word);
        for (int i = 1; i <= word.size(); ++i) {
            for (int j = 0; j <= word.size()-i; ++j) {
                string s;
                if (0 != j) {
                    s = word.substr(0, j);
                }
                s += to_string(i);
                if (j+i+1 >= word.size()) {
                    result.push_back(s+word.substr(j+i));    
                } else {
                    s += word[j+i];
                    vector<string> r = generateAbbreviations(word.substr(j+i+1));
                    for (int k = 0; k < r.size(); ++k) {
                        result.push_back(s+r[k]);
                    }
                }
            }
        }
        return result;
    }
};
