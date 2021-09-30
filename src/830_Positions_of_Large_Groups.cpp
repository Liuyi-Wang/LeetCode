static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int l = 0;
        for (int r = 1; r < S.size(); ++r) {
            if (S[l] == S[r]) {
                continue;
            }
            if (r-l >= 3) {
                vector<int> v = {l, r-1};
                result.push_back(v);
            }
            l = r;
        }
        if (S.size()-l >= 3) {
            vector<int> v = {l, S.size()-1};
            result.push_back(v);
        }
        return result;
    }
};
