static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        for (auto p:paths) {
            stringstream ss(p);
            string path;
            ss >> path;
            string s;
            while (ss >> s) {
                int i = s.find_first_of('(');
                string file = s.substr(0, i);
                string content = s.substr(i+1, s.size()-1-i);
                hash[content].push_back(path+"/"+file);
            }
        }
        vector<vector<string>> result;
        for (unordered_map<string, vector<string>>::iterator it = hash.begin(); it != hash.end(); ++it) {
            if (1 == it->second.size()) {
                continue;
            }
            result.push_back(it->second);
        }
        return result;
    }
};
