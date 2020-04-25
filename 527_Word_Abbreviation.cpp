static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const string &s1,
                                const string &s2) {
            if (s1.size() != s2.size()) {
                return s1.size() < s2.size();
            }
            if (s1[0] != s2[0]) {
                return s1[0] < s2[0];
            }
            if (s1.back() != s2.back()) {
                return s1.back() < s2.back();
            }
            for (int i = 1; i < s1.size(); ++i) {
                if (s1[i] != s2[i]) {
                    return s1[i] < s2[i];
                }
            }
            return true;
        }     
    };
    
    string solve(const string &s, int i) {
        if (i >= static_cast<int>(s.size())-3) {
            return s;
        }
        return s.substr(0, i+1)+to_string(s.size()-2-i)+s.back();
    }
    
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, int> hash;
        for (int i = 0; i < dict.size(); ++i) {
            hash[dict[i]] = i;
        }
        sort(dict.begin(), dict.end(), less_than());
        vector<string> result(dict.size());
        for (int i = 0; i < dict.size();) {
            int j = i+1;
            while (j < dict.size() && 
                   dict[j-1].size() == dict[j].size() && 
                   dict[j-1][0] == dict[j][0] &&
                   dict[j-1].back() == dict[j].back()) {
                ++j;
            }
            int idx = i;
            int last_idx = 0;
            while (idx < j-1) {
                int this_idx = 1;
                for (; this_idx < dict[idx].size(); ++this_idx) {
                    if (dict[idx][this_idx] != dict[idx+1][this_idx]) {
                        break;
                    }
                }
                result[hash[dict[idx]]] = solve(dict[idx], max(last_idx, this_idx));
                last_idx = this_idx;
                ++idx;
            }
            result[hash[dict[j-1]]] = solve(dict[j-1], last_idx);
            i = j;
        }
        return result;
    }
};
