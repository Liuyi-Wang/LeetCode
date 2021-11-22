/**
 *  Time:
 *  O(nn+nnlognn)
 *  Space:
 *  O(nn)
 */
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        heap.push({0, 0, grid[0][0]});
        visited[0][0] = true;
        int t = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!heap.empty()) {
            while (!heap.empty() && heap.top()[2] <= t) {
                vector<int> v = heap.top();
                heap.pop();
                if (v[0] == m-1 && v[1] == n-1) {
                    return t;
                }
                for (int i = 0; i < 4; ++i) {
                    int X = v[0]+directions[i].first;
                    int Y = v[1]+directions[i].second;
                    if (X < 0 || Y < 0 || X == m || Y == n) {
                        continue;
                    }
                    if (visited[X][Y]) {
                        continue;
                    }
                    heap.push({X, Y, grid[X][Y]});
                    visited[X][Y] = true;
                }
            }
            ++t;
        }
        return t;
    }
};
