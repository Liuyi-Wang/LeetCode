static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for (const auto &p:prerequisites) {
            graph[p[0]].push_back(p[1]);
            ++in[p[1]];
        }
        queue<int> q;
        for (int i = 0; i < in.size(); ++i) {
            if (0 == in[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (auto i:graph[c]) {
                --in[i];
                if (0 == in[i]) {
                    q.push(i);
                }
            }
        }
        for (auto i:in) {
            if (0 != i) {
                return false;
            }
        }
        return true;
    }
};
