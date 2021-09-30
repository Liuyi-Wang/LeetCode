static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> s_b;
        unordered_map<int, bool> s_v;
        for (int i = 0; i < routes.size(); ++i) {
            for (auto s:routes[i]) {
                s_b[s].push_back(i);
                s_v[s] = false;
            }
        }
        vector<bool> b_v(routes.size(), false);
        queue<vector<int>> q;
        vector<int> v(1, S);
        q.push(v);
        s_v[S] = true;
        int n = 0;
        while (!q.empty()) {
            v = q.front();
            q.pop();
            vector<int> next;
            for (int k = 0; k < v.size(); ++k) {
                S = v[k];
                if (S == T) {
                    return n;
                }
                for (int i = 0; i < s_b[S].size(); ++i) {
                    if (b_v[s_b[S][i]]) {
                        continue;
                    }
                    b_v[s_b[S][i]] = true;
                    for (int j = 0; j < routes[s_b[S][i]].size(); ++j) {
                        if (!s_v[routes[s_b[S][i]][j]]) {
                            next.push_back(routes[s_b[S][i]][j]);
                            s_v[routes[s_b[S][i]][j]] = true;
                        }
                    }
                }
            }
            if (0 == next.size()) {
                return -1;
            }
            q.push(next);
            ++n;
        }
        return n;
    }
};
