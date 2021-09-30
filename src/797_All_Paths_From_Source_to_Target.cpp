static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<vector<int>>& graph, int node, vector<int> path, vector<vector<int>>& result) {
        if (graph.size()-1 == node) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < graph[node].size(); ++i) {
            path.push_back(graph[node][i]);;
            solve(graph, graph[node][i], path, result);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path(1, 0);
        solve(graph, 0, path, result);
        return result;
    }
};
