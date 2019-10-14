static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, string> i_s;
        unordered_map<int, string> i_t;
        for (int i = 0; i < indexes.size(); ++i) {
            i_s[indexes[i]] = sources[i];
            i_t[indexes[i]] = targets[i];
        }
        sort(indexes.begin(), indexes.end());
        string result;
        int index = 0;
        if (0 != indexes[0]) {
            result += S.substr(0, indexes[0]);
        }
        for (int i = 0; i < indexes.size(); ++i) {
            string source = i_s[indexes[i]];
            if (S.substr(indexes[i], source.size()) == source) {
                result += i_t[indexes[i]];
            } else {
                result += S.substr(indexes[i], source.size());
            }
            index = indexes[i]+source.size()-1;
            if (i != indexes.size()-1) {
                result += S.substr(indexes[i]+source.size(), indexes[i+1]-indexes[i]-source.size());
                index += indexes[i+1]-indexes[i]-source.size();
            }
        }
        ++index;
        if (index < S.size()) {
            result += S.substr(index, S.size()-index);
        }
        return result;
    }
};
