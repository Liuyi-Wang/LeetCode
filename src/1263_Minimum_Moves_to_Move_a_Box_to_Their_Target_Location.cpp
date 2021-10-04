class Solution {
public:
    struct State {
        int d_bi;
        int d_bj;
        int d_pi;
        int d_pj;
        State(int bi, int bj, int pi, int pj): d_bi(bi), d_bj(bj), d_pi(pi), d_pj(pj) {}
    };
    
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int bi, bj, pi, pj, ti, tj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    bi = i;
                    bj = j;
                } else if (grid[i][j] == 'S') {
                    pi = i;
                    pj = j;
                } else if (grid[i][j] == 'T') {
                    ti = i;
                    tj = j;
                }
            }
        }
        deque<State> q;
        q.push_back(State(bi, bj, pi, pj));
        vector<vector<vector<vector<int>>>> moves(20, vector<vector<vector<int>>>(20, vector<vector<int>>(20, vector<int>(20, -1))));
        moves[bi][bj][pi][pj] = 0;
        vector<pair<int, int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            State s = q.front();
            q.pop_front();
            if (s.d_bi == ti && s.d_bj == tj) {
                return moves[s.d_bi][s.d_bj][s.d_pi][s.d_pj];
            }
            for (int k = 0; k < 4; ++k) {
                int PI = s.d_pi + move[k].first;
                int PJ = s.d_pj + move[k].second;
                if (PI == s.d_bi && PJ == s.d_bj) {
                    /// Push
                    int BI = s.d_bi + move[k].first;
                    int BJ = s.d_bj + move[k].second;
                    if (BI < 0 || BJ < 0 || BI >= m || BJ >= n) {
                        continue;
                    }
                    if (grid[BI][BJ] == '#') {
                        continue;
                    }
                    if (moves[BI][BJ][PI][PJ] != -1) {
                        continue;
                    }
                    moves[BI][BJ][PI][PJ] = moves[s.d_bi][s.d_bj][s.d_pi][s.d_pj] + 1;
                    q.push_back(State(BI, BJ, PI, PJ));
                } else {
                    /// No Push
                    if (PI < 0 || PJ < 0 || PI >= m || PJ >= n) {
                        continue;
                    }
                    if (grid[PI][PJ] == '#') {
                        continue;
                    }
                    if (moves[s.d_bi][s.d_bj][PI][PJ] != -1) {
                        continue;
                    }
                    moves[s.d_bi][s.d_bj][PI][PJ] = moves[s.d_bi][s.d_bj][s.d_pi][s.d_pj];
                    q.push_front(State(s.d_bi, s.d_bj, PI, PJ));
                }
            }
        }
        return -1;
    }
};
