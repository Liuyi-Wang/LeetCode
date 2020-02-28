static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct lexical_larger {
        inline bool operator() (const string &s1,
                                const string &s2) {
            return s1 > s2;
        }
    };
    
    void solve(map<string, priority_queue<string, vector<string>, lexical_larger>> &dict, const string &a, vector<string> &result) {
        while (dict[a].size()) {
            string b = dict[a].top();
            dict[a].pop();
            solve(dict, b, result);
        }
        result.push_back(a);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, lexical_larger>> dict;
        for (const auto &t:tickets) {
            dict[t[0]].push(t[1]);
        }
        vector<string> result;
        string a = "JFK";
        solve(dict, a, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
