static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, vector<string>> m;
        vector<string> v;
        for (const auto& l:logs) {
            stringstream ss(l);
            string s;
            ss >> s;
            ss >> s;
            //cout << s << endl;
            if (!isalpha(s[0])) {
                v.push_back(l);
            } else {
                int i = l.find_first_of(' ');
                m[l.substr(i+1)].push_back(l);
            }
        }
        vector<string> result;
        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            result.insert(result.end(), it->second.begin(), it->second.end());
        }
        result.insert(result.end(), v.begin(), v.end());
        return result;
    }
};
