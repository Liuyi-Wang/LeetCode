static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> map(N+1, vector<int>());
        for (const auto& d:dislikes) {
            map[d[0]].push_back(d[1]);
            map[d[1]].push_back(d[0]);
        }
        vector<int> g(N+1, 0);
        stack<int> s;
        int count = 0;
        int index = 1;
        while (count != N) {
            while (index <= N) {
                if (0 == g[index]) {
                    g[index] = 1;
                    ++count;
                    ++index;
                    break;
                }
                ++index;
            }
            s.push(index-1);
            while (!s.empty()) {
                int i = s.top();
                s.pop();
                for (int j = 0; j < map[i].size(); ++j) {
                    if (g[i] == g[map[i][j]]) {
                        return false;
                    }
                    if (0 == g[map[i][j]]) {
                        s.push(map[i][j]);
                        ++count;
                    }
                    g[map[i][j]] = -g[i];
                }
            }
        }
        return true;
    }
};
