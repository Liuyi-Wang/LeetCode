class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0, d->d
        // 1, l->l
        // 2, l->d
        // 3, d->l
        vector<int> d_r = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> d_c = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int R = i+d_r[k];
                    int C = j+d_c[k];
                    if (R < 0 || C < 0 || R >= board.size() || C >= board[i].size() || 0 == board[R][C] || 3 == board[R][C]) {
                        continue;
                    }
                    ++count;
                }
                if (board[i][j] && (count < 2 || count > 3)) {
                    board[i][j] = 2;
                } else if (0 == board[i][j] && 3 == count) {
                    board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
