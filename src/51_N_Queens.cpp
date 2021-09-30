class Solution {
public:
    void solve(const int &n, vector<string> &board) {
        if (board.size() == n) {
            d_result.push_back(board);
            return;
        }
        string row(n, '.');
        for (int i = 0; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < board.size(); ++j) {
                int diff = board.size()-j;
                if ('Q' == board[j][i] || (i-diff >= 0 && 'Q' == board[j][i-diff]) || (i+diff < n && 'Q' == board[j][i+diff])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                continue;
            }
            row[i] = 'Q';
            board.push_back(row);
            solve(n, board);
            board.pop_back();
            row[i] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        solve(n, board);
        return d_result;
    }
    
private:
    vector<vector<string>> d_result;
};
