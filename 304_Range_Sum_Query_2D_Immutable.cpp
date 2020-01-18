static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (0 == m) {
            return;
        }
        int n = matrix[0].size();
        if (0 == n) {
            return;
        }
        d_s = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            d_s[i+1][1] = d_s[i][1]+matrix[i][0];
        }
        for (int j = 0; j < n; ++j) {
            d_s[1][j+1] = d_s[1][j]+matrix[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                d_s[i+1][j+1] = matrix[i][j]+d_s[i][j+1]+d_s[i+1][j]-d_s[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return d_s[row2+1][col2+1]+d_s[row1][col1]-d_s[row1][col2+1]-d_s[row2+1][col1];
    }
    
private:
    vector<vector<int>> d_s;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
