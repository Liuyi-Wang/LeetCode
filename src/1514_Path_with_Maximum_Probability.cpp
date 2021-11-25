/**
 *  Time:
 *  O(ElogV)
 *  Space:
 *  O(V+E)
 */
class Solution {
public:
    struct Node {
        int d_id;
        double d_prob;
        Node(int id, double prob): d_id(id), d_prob(prob) {}
    };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<Node>> connects(n, vector<Node>());
        for (int i = 0; i < edges.size(); ++i) {
            connects[edges[i][0]].push_back(Node(edges[i][1], succProb[i]));
            connects[edges[i][1]].push_back(Node(edges[i][0], succProb[i]));
        }
        auto cmp = [](const Node& n1, const Node& n2) {
            return n1.d_prob > n2.d_prob;
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> heap(cmp);
        heap.push(Node(start, 0));
        vector<bool> visited(n, false);
        while (!heap.empty()) {
            int i = heap.top().d_id;
            double prob = heap.top().d_prob;
            heap.pop();
            if (i == end) {
                return 1-prob;
            }
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            for (auto connect:connects[i]) {
                if (visited[connect.d_id]) {
                    continue;
                }
                heap.push(Node(connect.d_id, 1-(1-prob)*connect.d_prob));
            }
        }
        return 0;
    }
};
