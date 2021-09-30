static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool u = false, l = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (0 == matrix[i][0]) {
                l = true;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (0 == matrix[0][j]) {
                u = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (0 == matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            if (0 == matrix[i][0]) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (0 == matrix[0][j]) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (u) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
        if (l) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
