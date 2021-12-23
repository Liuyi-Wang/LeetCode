/**
 *  Time:
 *  O(V+E)
 *  Space:
 *  O(V+E)
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> connects(n, vector<int>());
        vector<int> in(n, 0);
        int allin = 0;
        for (auto v:prerequisites) {
            connects[v[1]].push_back(v[0]);
            ++in[v[0]];
            ++allin;
        }
        queue<int> q;
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            result.push_back(i);
            for (auto next:connects[i]) {
                --in[next];
                --allin;
                if (in[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (allin > 0) {
            return {};
        }
        return result;
    }
};
