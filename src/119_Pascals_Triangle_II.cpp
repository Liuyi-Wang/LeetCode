static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> rows;
        rows.push_back(vector<int>(1,1));
        if (0 == rowIndex) {
            return rows[0];
        }
        rows.push_back(vector<int>(2,1));
        if (1 == rowIndex) {
            return rows[1];
        }
        for (int i = 2; i <= rowIndex; ++i) {
            rows[i%2] = vector<int>(i+1, 1);
            for (int j = 1; j < i; ++j) {
                rows[i%2][j] = rows[(i-1)%2][j-1]+rows[(i-1)%2][j];
            }
        }
        return rows[rowIndex%2];
    }
};
