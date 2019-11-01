static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct greater_than {
        inline bool operator() (const pair<int, string> &p1,
                                const pair<int, string> &p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }    
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const auto& w:words) {
            ++count[w];
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater_than> min_heap;
        for (unordered_map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
            min_heap.push(pair<int, string>(it->second, it->first));
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        vector<string> result(k, "");
        for (int i = result.size()-1; i >= 0; --i) {
            result[i] = min_heap.top().second;
            min_heap.pop();
        }
        return result;
    }
};
