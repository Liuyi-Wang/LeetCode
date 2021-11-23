/**
 *  Time:
 *  O(mnlogmn)
 *  Space:
 *  O(mn)
 */
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({start[0], start[1], 0});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!heap.empty()) {
            start = heap.top();
            heap.pop();
            if (start[0] == destination[0] && start[1] == destination[1]) {
                return start[2];
            }
            if (visited[start[0]][start[1]]) {
                continue;
            }
            visited[start[0]][start[1]] = true;
            for (int i = 0; i < 4; ++i) {
                int distance = 0;
                int X = start[0], Y = start[1];
                while (X+directions[i].first >= 0 && 
                       Y+directions[i].second >= 0 && 
                       X+directions[i].first < m && 
                       Y+directions[i].second < n && 
                       maze[X+directions[i].first][Y+directions[i].second] != 1) {
                    X += directions[i].first;
                    Y += directions[i].second;
                    ++distance;
                }
                if (!visited[X][Y]) {
                    heap.push({X, Y, start[2]+distance});
                }
            }
        }
        return -1;
    }
};
