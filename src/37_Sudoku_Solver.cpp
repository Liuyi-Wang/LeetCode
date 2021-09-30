static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool valid(vector<vector<char>> &board, int i, int j, char c) {
        for (int k = 0; k < 9; ++k) {
            if (c == board[i][k]) {
                return false;
            }
        }
        for (int k = 0; k < 9; ++k) {
            if (c == board[k][j]) {
                return false;
            }
        }
        int row = (i/3)*3;
        int col = (j/3)*3;
        for (int m = row; m < row+3; ++m) {
            for (int n = col; n < col+3; ++n) {
                if (c == board[m][n]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int i, int j) {
        if (9 == j) {
            return solve(board, i+1, 0);
        }
        if (9 == i) {
            return true;
        }
        if ('.' == board[i][j]) {
            for (char c = '1'; c <= '9'; ++c) {
                if (!valid(board, i, j, c)) {
                    continue;
                }
                board[i][j] = c;
                if (solve(board, i, j+1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        } else {
            return solve(board, i, j+1);
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
