static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        d_n = n;
        d_row = vector<int>(n, 0);
        d_col = vector<int>(n, 0);
        d_lr = 0;
        d_rl = 0;
        d_result = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (0 != d_result) {
            return d_result;
        }
        if (1 == player) {
            ++d_row[row];
            if (d_n == d_row[row]) {
                d_result = 1;
                return d_result;
            }
            ++d_col[col];
            if (d_n == d_col[col]) {
                d_result = 1;
                return d_result;
            }
            if (row == col) {
                ++d_lr;
            }
            if (d_n == d_lr) {
                d_result = 1;
                return d_result;
            }
            if (d_n-1 == row+col) {
                ++d_rl;
            }
            if (d_n == d_rl) {
                d_result = 1;
                return d_result;
            }
        } else {
            --d_row[row];
            if (-d_n == d_row[row]) {
                d_result = 2;
                return d_result;
            }
            --d_col[col];
            if (-d_n == d_col[col]) {
                d_result = 2;
                return d_result;
            }
            if (row == col) {
                --d_lr;
            }
            if (-d_n == d_lr) {
                d_result = 2;
                return d_result;
            }
            if (d_n-1 == row+col) {
                --d_rl;
            }
            if (-d_n == d_rl) {
                d_result = 2;
                return d_result;
            }
        }
        return d_result;
    }
    
private:
    int d_n;
    vector<int> d_row;
    vector<int> d_col;
    int d_lr;
    int d_rl;
    int d_result;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
