static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool find(int r, int c, vector<vector<char>> &board, const string &word, int n) {
        if (word.size() == n) {
            return true;
        }
        for (int i = 0; i < d_r.size(); ++i) {
            int R = r+d_r[i];
            int C = c+d_c[i];
            if (R < 0 || C < 0 || R >= board.size() || C >= board[0].size()) {
                continue;
            }
            if (word[n] != board[R][C]) {
                continue;
            }
            char l = board[R][C];
            board[R][C] = ' ';
            if (find(R, C, board, word, n+1)) {
                return true;
            }
            board[R][C] = l;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        d_r = {-1, 0, 1, 0};
        d_c = {0, 1, 0, -1};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j]) {
                    char l = board[i][j];
                    board[i][j] = ' ';
                    if (find(i, j, board, word, 1)) {
                        return true;
                    }
                    board[i][j] = l;
                }
            }
        }
        return false;
    }
    
private:
    vector<int> d_r;
    vector<int> d_c;
};
