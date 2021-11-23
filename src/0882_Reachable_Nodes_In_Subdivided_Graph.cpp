/**
 *  Time:
 *  O(E+V+ElogV)
 *  Space:
 *  O(E+V)
 */
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> connects(n, vector<pair<int, int>>());
        for (auto edge:edges) {
            connects[edge[0]].push_back({edge[1], edge[2]});
            connects[edge[1]].push_back({edge[0], edge[2]});
        }
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0});
        vector<int> moves(n, INT_MAX);
        while (!heap.empty()) {
            pair<int, int> p = heap.top();
            heap.pop();
            if (p.second >= moves[p.first]) {
                continue;
            }
            moves[p.first] = p.second;
            for (auto connect:connects[p.first]) {
                if (p.second+connect.second+1 <= maxMoves && p.second+connect.second+1 < moves[connect.first]) {
                    heap.push({connect.first, p.second+connect.second+1});
                }
            }
        }
        int result = 0;
        for (auto edge:edges) {
            int sum1 = max(0, maxMoves-moves[edge[0]]);
            int sum2 = max(0, maxMoves-moves[edge[1]]);
            result += min(edge[2], sum1+sum2);
        }
        for (int i = 0; i < n; ++i) {
            if (moves[i] <= maxMoves) {
                ++result;
            }
        }
        return result;
    }
};
