class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int x, y;
        bool find = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (1 == A[i][j]) {
                    x = i;
                    y = j;
                    A[x][y] = 2;
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        queue<int> qx, qy;
        stack<int> sx, sy;
        sx.push(x);
        sy.push(y);
        qx.push(x);
        qy.push(y);
        map<pair<int, int>, int> dist;
        while (!sx.empty()) {
            x = sx.top();
            sx.pop();
            y = sy.top();
            sy.pop();
            dist[pair<int, int>(x, y)] = 0;
            if (x > 0 && 1 == A[x-1][y]) {
                A[x-1][y] = 2;
                sx.push(x-1);
                sy.push(y);
                qx.push(x-1);
                qy.push(y);
            }
            if (y < n-1 && 1 == A[x][y+1]) {
                A[x][y+1] = 2;
                sx.push(x);
                sy.push(y+1);
                qx.push(x);
                qy.push(y+1);
            }
            if (x < m-1 && 1 == A[x+1][y]) {
                A[x+1][y] = 2;
                sx.push(x+1);
                sy.push(y);
                qx.push(x+1);
                qy.push(y);
            }
            if (y > 0 && 1 == A[x][y-1]) {
                A[x][y-1] = 2;
                sx.push(x);
                sy.push(y-1);
                qx.push(x);
                qy.push(y-1);
            }
        }
        while (!qx.empty()) {
            x = qx.front();
            qx.pop();
            y = qy.front();
            qy.pop();
            int d = dist[pair<int, int>(x, y)];
            if (x > 0 && 1 == A[x-1][y]) {
                return d;
            } else if (x > 0 && 0 == A[x-1][y]) {
                A[x-1][y] = 2;
                qx.push(x-1);
                qy.push(y);
                dist[pair<int, int>(x-1, y)] = d+1;
            }
            if (y < n-1 && 1 == A[x][y+1]) {
                return d;
            } else if (y < n-1 && 0 == A[x][y+1]) {
                A[x][y+1] = 2;
                qx.push(x);
                qy.push(y+1);
                dist[pair<int, int>(x, y+1)] = d+1;
            }
            if (x < m-1 && 1 == A[x+1][y]) {
                return d;
            } else if (x < m-1 && 0 == A[x+1][y]) {
                A[x+1][y] = 2;
                qx.push(x+1);
                qy.push(y);
                dist[pair<int, int>(x+1, y)] = d+1;
            }
            if (y > 0 && 1 == A[x][y-1]) {
                return d;
            } else if (y > 0 && 0 == A[x][y-1]) {
                A[x][y-1] = 2;
                qx.push(x);
                qy.push(y-1);
                dist[pair<int, int>(x, y-1)] = d+1;
            }
        }
        return -1;
    }
};
