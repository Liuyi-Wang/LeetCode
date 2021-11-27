class Solution {
    int m;
    int n;
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        this->m = rowCosts.size();
        this->n = colCosts.size();
        int result = 0;
        if (homePos[0] > startPos[0]) {
            for (int i = startPos[0]; i < homePos[0]; ++i) {
                result += rowCosts[i+1];
            }
        } else {
            for (int i = startPos[0]; i > homePos[0]; --i) {
                result += rowCosts[i-1];
            }
        }
        if (homePos[1] > startPos[1]) {
            for (int j = startPos[1]; j < homePos[1]; ++j) {
                result += colCosts[j+1];
            }
        } else {
            for (int j = startPos[1]; j > homePos[1]; --j) {
                result += colCosts[j-1];
            }
        }
        return result;
        /*
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() > v2.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({startPos[0], startPos[1], 0});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!heap.empty()) {
            int x = heap.top()[0];
            int y = heap.top()[1];
            int cost = heap.top()[2];
            heap.pop();
            if (x == homePos[0] && y == homePos[1]) {
                return cost;
            }
            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int X = x + dirs[i].first;
                int Y = y + dirs[i].second;
                if (X < 0 || Y < 0 || X >= m || Y >= n) {
                    continue;
                }
                if (visited[X][Y]) {
                    continue;
                }
                if (i%2 == 0) {
                    heap.push({X, Y, cost+rowCosts[X]});
                } else {
                    heap.push({X, Y, cost+colCosts[Y]});
                }
            }
        }
        return -1;
        */
    }
};
