static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (0 == poured) {
            return 0;
        }
        vector<vector<double>> glasses;
        glasses.push_back(vector<double>(1, poured));
        for (int i = 0; i < query_row; ++i) {
            bool neverFull = true;
            glasses.push_back(vector<double>(i+2, 0));
            for (int j = 0; j < glasses[i].size(); ++j) {
                if (glasses[i][j] > 1) {
                    glasses[i+1][j] += (glasses[i][j]-1)/2;
                    glasses[i+1][j+1] += (glasses[i][j]-1)/2;
                    neverFull = false;
                }
            }
            if (neverFull) {
                return 0;
            }
        }
        return glasses.back()[query_glass]>1?1:glasses.back()[query_glass];
    }
};
