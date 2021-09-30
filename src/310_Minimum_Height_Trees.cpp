static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (1 == n) {
            return {0};
        }
        if (2 == n) {
            return {0, 1};
        }
        vector<vector<int>> graph(n, vector<int>());
        vector<int> in(n, 0);
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            ++in[e[0]];
            ++in[e[1]];
        }
        queue<int> q;
        for (int i = 0; i < in.size(); ++i) {
            if (1 == in[i]) {
                q.push(i);
            }
        }
        while (n > 2) {
            int size = q.size();
            cout << size << endl;
            for (int j = 0; j < size; ++j) {
                int node = q.front();
                q.pop();
                --n;
                for (auto i:graph[node]) {
                    --in[i];
                    if (1 == in[i]) {
                        q.push(i);
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
