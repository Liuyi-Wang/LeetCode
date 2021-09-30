static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int i = m-1, j = 0;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (target == matrix[i][j]) {
                return true;
            } else if (target > matrix[i][j]) {
                ++j;
            } else {
                --i;
            }
        }
        return false;
    }
};
