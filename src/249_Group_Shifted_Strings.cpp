static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> index;
        vector<vector<string>> result;
        for (const auto &s:strings) {
            string t;
            for (int i = 1; i < s.size(); ++i) {
                t += to_string((s[i]-s[i-1]+26)%26)+"|";
            }
            if (index.find(t) == index.end()) {
                index[t] = result.size();
                result.push_back({});
            }
            result[index[t]].push_back(s);
        }
        return result;
    }
};
