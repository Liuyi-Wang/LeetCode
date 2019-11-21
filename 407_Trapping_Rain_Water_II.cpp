static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct greater_than {
        inline bool operator() (const pair<int, pair<int, int>> &p1,
                                const pair<int, pair<int, int>> &p2) {
            return p1.first > p2.first;
        }    
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (0 == heightMap.size() || 0 == heightMap[0].size()) {
            return 0;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater_than> q;
        int r = heightMap.size(), c = heightMap[0].size();
        for (int i = 0; i < r; ++i) {
            q.push({heightMap[i][0], {i, 0}});
            heightMap[i][0] = -1;
            q.push({heightMap[i][c-1], {i, c-1}});
            heightMap[i][c-1] = -1;
        }
        for (int j = 1; j < c-1; ++j) {
            q.push({heightMap[0][j], {0, j}});
            heightMap[0][j] = -1;
            q.push({heightMap[r-1][j], {r-1, j}});
            heightMap[r-1][j] = -1;
        }
        int result = 0;
        int level = 1;
        vector<int> d_r = {-1, 0, 1, 0};
        vector<int> d_c = {0, 1, 0, -1};
        while (!q.empty()) {
            if (level < q.top().first) {
                ++level;
                continue;
            }
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            for (int i = 0; i < d_r.size(); ++i) {
                int R = row+d_r[i];
                int C = col+d_c[i];
                if (R < 0 || C < 0 || R >= r || C >= c) {
                    continue;
                }
                if (-1 == heightMap[R][C]) {
                    continue;
                }
                if (heightMap[R][C] < level) {
                    result += level-heightMap[R][C];
                }
                q.push({heightMap[R][C], {R, C}});
                heightMap[R][C] = -1;
            }
        }
        return result;
    }
};
