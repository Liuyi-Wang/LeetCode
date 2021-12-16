/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> connects;
        for (auto edge:edges) {
            connects[edge[0]].insert(edge[1]);
            connects[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for (auto it:connects) {
            int v = it.first;
            int n = it.second.size();
            if (n == 1) {
                q.push(v);
            }
        }
        vector<bool> nodes(n, true);
        while (n > 2) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int v = q.front();
                q.pop();
                nodes[v] = false;
                --n;
                for (auto connect:connects[v]) {
                    connects[connect].erase(v);
                    if (connects[connect].size() == 1) {
                        q.push(connect);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < nodes.size(); ++i) {
            if (n == 0) {
                break;
            }
            if (nodes[i]) {
                result.push_back(i);
                --n;
            }
        }
        return result;
    }
};
