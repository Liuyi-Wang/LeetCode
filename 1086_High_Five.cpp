static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> hash;
        for (auto p:items) {
            if (hash[p[0]].size() < 5) {
                hash[p[0]].push(p[1]);
            } else if (p[1] > hash[p[0]].top()) {
                hash[p[0]].pop();
                hash[p[0]].push(p[1]);
            }
        }
        vector<vector<int>> result;
        for (auto p:hash) {
            vector<int> v;
            v.push_back(p.first);
            int sum = 0;
            while (!p.second.empty()) {
                sum += p.second.top();
                p.second.pop();
            }
            v.push_back(sum/5);
            result.push_back(v);
        }
        return result;
    }
};
