static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<int> &quiet, vector<int> &result, int i, map<int, set<int>> &rich) {
        int p = i;
        for (set<int>::iterator cit = rich[i].begin(); cit != rich[i].end(); ++cit) {
            if (result[*cit] == -1) {
                solve(quiet, result, *cit, rich);
            }
            if (quiet[p] > quiet[result[*cit]]) {
                p = result[*cit];
            }
        }
        result[i] = p;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        map<int, set<int>> rich;
        for (const auto &r:richer) {
            rich[r[1]].insert(r[0]);
        }
        vector<int> result(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); ++i) {
            if (-1 != result[i]) {
                continue;
            }
            solve(quiet, result, i, rich);
        }
        return result;
    }
};
