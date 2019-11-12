static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(const string &w, unordered_map<char, int> &counts, const int &count) {
        unordered_map<char, int> wcounts;
        int wcount = 0;
        for (auto c:w) {
            if (!isalpha(c)) {
                continue;
            }
            ++wcounts[tolower(c)];
            if (counts.find(tolower(c)) != counts.end() && wcounts[tolower(c)] == counts[tolower(c)]) {
                ++wcount;
            }
        }
        return wcount == count;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> counts;
        int count = 0;
        for (auto c:licensePlate) {
            if (!isalpha(c)) {
                continue;
            }
            ++counts[tolower(c)];
            if (1 == counts[tolower(c)]) {
                ++count;
            }
        }
        string result;
        int len = INT_MAX;
        for (const auto &w:words) {
            if (w.size() < len && solve(w, counts, count)) {
                result = w;
                len = result.size();
            }
        }
        return result;
    }
};
