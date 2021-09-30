class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ri = -1, rj = -1;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if ('R' == board[i][j]) {
                    ri = i;
                    rj = j;
                    break;
                }
            }
            if (-1 != ri) {
                break;
            }
        }
        int result = 0;
        for (int i = ri-1; i >= 0; --i) {
            if ('B' == board[i][rj]) {
                break;
            }
            if ('p' == board[i][rj]) {
                ++result;
                break;
            }
        }
        for (int i = ri+1; i <= 7; ++i) {
            if ('B' == board[i][rj]) {
                break;
            }
            if ('p' == board[i][rj]) {
                ++result;
                break;
            }
        }
        for (int j = rj-1; j >= 0; --j) {
            if ('B' == board[ri][j]) {
                break;
            }
            if ('p' == board[ri][j]) {
                ++result;
                break;
            }
        }
        for (int j = rj+1; j <= 7; ++j) {
            if ('B' == board[ri][j]) {
                break;
            }
            if ('p' == board[ri][j]) {
                ++result;
                break;
            }
        }
        return result;
    }
};
