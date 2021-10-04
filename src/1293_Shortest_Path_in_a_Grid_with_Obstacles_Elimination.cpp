class Solution {
public:
    struct Status {
        int d_i;
        int d_j;
        int d_k;
        Status(int i, int j, int k): d_i(i), d_j(j), d_k(k) {}
    };
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }
        int result = 0;
        queue<Status> q;
        //vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        bool visited[40][40][1601] = {0};
        q.push(Status(0, 0, k));
        visited[0][0][k] = true;
        vector<pair<int, int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                Status s = q.front();
                q.pop();
                for (auto p:move) {
                    int I = s.d_i + p.first;
                    int J = s.d_j + p.second;
                    if (I < 0 || J < 0 || I >= m || J >= n) {
                        continue;
                    }
                    if (I == m-1 && J == n-1) {
                        return result+1;
                    }
                    if (grid[I][J] == 1) {
                        if (s.d_k == 0) {
                            continue;
                        }
                        if (visited[I][J][s.d_k-1]) {
                            continue;
                        }
                        q.push(Status(I, J, s.d_k-1));
                        visited[I][J][s.d_k-1] = true;
                    } else {
                        if (visited[I][J][s.d_k]) {
                            continue;
                        }
                        q.push(Status(I, J, s.d_k));
                        visited[I][J][s.d_k] = true;
                    }
                }
                --size;
            }
            ++result;
        }
        return -1;
    }
};
