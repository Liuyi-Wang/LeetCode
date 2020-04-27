static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(string &s) {
        for (int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        }
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (const auto &b:banned) {
            ban.insert(b);
        }
        unordered_map<string, int> counts;
        string result;
        int count = 0;
        int i = 0;
        while (i < paragraph.size()) {
            int j = i;
            while (j < paragraph.size() && isalpha(paragraph[j])) {
                ++j;
            }
            string s = paragraph.substr(i, j-i);
            solve(s);
            if (ban.find(s) == ban.end()) {
                ++counts[s];
                if (count < counts[s]) {
                    result = s;
                    count = counts[s];
                }
            }
            i = j+1;
            while (i < paragraph.size() && !isalpha(paragraph[i])) {
                ++i;
            }
        }
        return result;
    }
};
