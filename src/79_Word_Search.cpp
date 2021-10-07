class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        d_m = board.size();
        d_n = board[0].size();
        d_directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < d_m; ++i) {
            for (int j = 0; j < d_n; ++j) {
                if (board[i][j] == word[0]) {
                    char c = board[i][j];
                    board[i][j] = '#';
                    if (sol1(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
    
    bool sol1(vector<vector<char>>& board, const string& word, int i, int j, int w) {
        if (w == word.size()) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int I = i+d_directions[k].first;
            int J = j+d_directions[k].second;
            if (I < 0 || J < 0 || I >= d_m || J >= d_n) {
                continue;
            }
            if (board[I][J] != word[w]) {
                continue;
            }
            char c = board[I][J];
            board[I][J] = '#';
            if (sol1(board, word, I, J, w+1)) {
                return true;
            }
            board[I][J] = c;
        }
        return false;
    }
    
private:
    int d_m;
    int d_n;
    vector<pair<int, int>> d_directions;
};
