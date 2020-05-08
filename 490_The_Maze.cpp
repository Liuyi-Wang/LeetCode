static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (0 == m) {
            return false;
        }
        int n = maze[0].size();
        if (0 == n) {
            return false;
        }
        if (start[0] == destination[0] && start[1] == destination[1]) {
            return true;
        }
        vector<vector<bool>> v(m, vector<bool>(n, false));
        stack<pair<int, int>> s;
        s.push({start[0], start[1]});
        v[start[0]][start[1]] = true;
        vector<int> d_i = {-1, 1, 0, 0};
        vector<int> d_j = {0, 0, -1, 1};
        while (!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();
            for (int k = 0; k < 4; ++k) {
                int I = p.first+d_i[k];
                int J = p.second+d_j[k];
                while (!(I < 0 || J < 0 || I >= m || J >= n || 1 == maze[I][J])) {
                    I += d_i[k];
                    J += d_j[k];
                }
                I -= d_i[k];
                J -= d_j[k];
                if (v[I][J]) {
                    continue;
                }
                if (I == destination[0] && J == destination[1]) {
                    return true;
                }
                v[I][J] = true;
                s.push({I, J});
            }
        }
        return false;
    }
};
