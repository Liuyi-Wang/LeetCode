/**
 *  Time:
 *  
 *  Space:
 *  O(2^M)
 */
class Solution {
public:
    int worker(int state) {
        int n = 0;
        while (state) {
            state &= (state-1);
            ++n;
        }
        return n;
    }
    
    int manhattan(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0]-bike[0])+abs(worker[1]-bike[1]);
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0});
        vector<int> dist(1024, INT_MAX);
        while (!heap.empty()) {
            pair<int, int> p = heap.top();
            heap.pop();
            int k = worker(p.first);
            if (k == n) {
                return p.second;
            }
            if (dist[p.first] <= p.second) {
                continue;
            }
            dist[p.first] = p.second;
            for (int i = 0; i < m; ++i) {
                if (((1<<i)&p.first) != 0) {
                    continue;
                }
                int distance = manhattan(workers[k], bikes[i]);
                if (distance+p.second < dist[(1<<i)|p.first]) {
                    heap.push({(1<<i)|p.first, distance+p.second});
                }
            }
        }
        return -1;
	}
};
