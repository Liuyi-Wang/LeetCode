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
        int u = 0, d = m-1;
        while (u+1 < d) {
            int mid = u + (d-u)/2;
            if (target == matrix[mid][0]) {
                return true;
            } else if (target < matrix[mid][0]) {
                d = mid-1;
            } else {
                u = mid;
            }
        }
        if (target == matrix[u][0] || target == matrix[d][0]) {
            return true;
        }
        int i;
        if (target > matrix[d][0]) {
            i = d;
        } else if (target > matrix[u][0]) {
            i = u;
        } else {
            return false;
        }
        int l = 0, r = n-1;
        while (l+1 < r) {
            int mid = l + (r-l)/2;
            if (target == matrix[i][mid]) {
                return true;
            } else if (target < matrix[i][mid]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if (target == matrix[i][l] || target == matrix[i][r]) {
            return true;
        }
        return false;
    }
};
