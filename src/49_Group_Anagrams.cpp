static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> index;
        for (const auto &s:strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (index.find(t) == index.end()) {
                index[t] = result.size();
                result.push_back({});
            }
            result[index[t]].push_back(s);
        }
        return result;
    }
};
