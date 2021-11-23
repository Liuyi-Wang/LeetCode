/**
 *  Time:
 *  O(nnlogn)
 *  Space:
 *  O(nk)
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> connects(n, vector<vector<int>>());
        for (auto flight:flights) {
            connects[flight[0]].push_back({flight[1], flight[2]});
        }
        k += 1;
        vector<vector<bool>> visited(n, vector<bool>(k+1, false));
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({src, 0, 0});
        while (!heap.empty()) {
            vector<int> v = heap.top();
            heap.pop();
            if (v[0] == dst) {
                return v[2];
            }
            if (visited[v[0]][v[1]]) {
                continue;
            }
            visited[v[0]][v[1]] = true;
            if (v[1] == k) {
                continue;
            }
            for (auto connect:connects[v[0]]) {
                if (visited[connect[0]][v[1]+1]) {
                    continue;
                }
                heap.push({connect[0], v[1]+1, v[2]+connect[1]});
            }
        }
        return -1;
    }
};
