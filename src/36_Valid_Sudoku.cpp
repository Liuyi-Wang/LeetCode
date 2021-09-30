static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' == board[i][j]) {
                    continue;
                }
                if (rows[i][board[i][j]-'1'] ||
                    cols[j][board[i][j]-'1'] ||
                    boxes[(i/3)*3+j/3][board[i][j]-'1']) {
                    return false;
                }
                rows[i][board[i][j]-'1'] = true;
                cols[j][board[i][j]-'1'] = true;
                boxes[(i/3)*3+j/3][board[i][j]-'1'] = true;
            }
        }
        return true;
    }
};
