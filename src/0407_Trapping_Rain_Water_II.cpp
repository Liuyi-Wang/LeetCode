/**
 *  Time:
 *  O(mn+mnlogmn)
 *  Space:
 *  O(mn)
 */
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            heap.push({i, 0, heightMap[i][0]});
            heap.push({i, n-1, heightMap[i][n-1]});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; ++j) {
            heap.push({0, j, heightMap[0][j]});
            heap.push({m-1, j, heightMap[m-1][j]});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        int result = 0;
        int h = 0;
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!heap.empty()) {
            vector<int> v = heap.top();
            heap.pop();
            h = max(h, v[2]);
            result += h-heightMap[v[0]][v[1]];
            
            queue<pair<int, int>> q;
            q.push({v[0], v[1]});
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < directions.size(); ++i) {
                    int X = p.first+directions[i].first;
                    int Y = p.second+directions[i].second;
                    if (X < 0 || Y < 0 || X == m || Y == n) {
                        continue;
                    }
                    if (visited[X][Y]) {
                        continue;
                    }
                    visited[X][Y] = true;
                    if (heightMap[X][Y] <= h) {
                        result += h-heightMap[X][Y];
                        q.push({X, Y});
                    } else {
                        heap.push({X, Y, heightMap[X][Y]});
                    }
                }
            }
        }
        return result;
    }
};
