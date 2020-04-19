static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size();
        if (0 == m) {
            return 0;
        }
        int n = picture[0].size();
        if (0 == n) {
            return 0;
        }
        vector<int> col(n, 0);
        unordered_map<string, int> row;
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if ('W' == picture[i][j]) {
                    continue;
                }
                ++col[j];
                ++count;
            }
            if (N == count) {
                ++row[string(picture[i].begin(), picture[i].end())];
            }
        }
        int result = 0;
        for (unordered_map<string, int>::iterator it = row.begin(); it != row.end(); ++it) {
            if (N != it->second) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if ('B' == it->first[j] && N == col[j]) {
                    result += N;
                }
            }
        }
        return result;
    }
};
