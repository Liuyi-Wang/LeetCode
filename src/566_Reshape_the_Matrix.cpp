static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size()*nums[0].size() != r*c) {
            return nums;
        }
        vector<vector<int>> result(r, vector<int>(c, 0));
        int x = 0, y = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                result[i][j] = nums[x][y++];
                if (y == nums[0].size()) {
                    ++x;
                    y = 0;
                }
            }
        }
        return result;
    }
};
