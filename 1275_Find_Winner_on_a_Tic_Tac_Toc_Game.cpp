static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        for (int i = 0; i < moves.size(); ++i) {
            if (0 == i%2) {
                board[moves[i][0]][moves[i][1]] = 'X';
            } else {
                board[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        for (int i = 0; i < 3; ++i) {
            if ('X' == board[i][0] && 'X' == board[i][1] && 'X' == board[i][2]) {
                return "A";    
            }
            if ('O' == board[i][0] && 'O' == board[i][1] && 'O' == board[i][2]) {
                return "B";    
            }
            if ('X' == board[0][i] && 'X' == board[1][i] && 'X' == board[2][i]) {
                return "A";
            }
            if ('O' == board[0][i] && 'O' == board[1][i] && 'O' == board[2][i]) {
                return "B";
            }
        }
        if ('X' == board[0][0] && 'X' == board[1][1] && 'X' == board[2][2]) {
            return "A";
        }
        if ('O' == board[0][0] && 'O' == board[1][1] && 'O' == board[2][2]) {
            return "B";
        }
        if ('X' == board[0][2] && 'X' == board[1][1] && 'X' == board[2][0]) {
            return "A";
        }
        if ('O' == board[0][2] && 'O' == board[1][1] && 'O' == board[2][0]) {
            return "B";
        }
        if (9 == moves.size()) {
            return "Draw";
        }
        return "Pending";
    }
};
