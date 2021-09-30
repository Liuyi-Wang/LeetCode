static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if (0 == m) {
            return 0;
        }
        int n = picture[0].size();
        if (0 == n) {
            return 0;
        }
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        vector<pair<int, int>> b;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('B' == picture[i][j]) {
                    ++row[i];
                    ++col[j];
                    b.push_back({i, j});
                }
            }
        }
        int result = 0;
        for (auto p:b) {
            if (1 == row[p.first] && 1 == col[p.second]) {
                ++result;
            }
        }
        return result;
    }
};
