static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const pair<int, int> &p1,
                                const pair<int, int> &p2) {
            return p1.first < p2.first;
        }    
    };
    
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> v;
        for (int i = 0; i < Profits.size(); ++i) {
            v.push_back({Capital[i], Profits[i]});
        }
        sort(v.begin(), v.end(), less_than());
        int i = 0;
        priority_queue<int> q;
        while (k > 0) {
            while (i < v.size() && W >= v[i].first) {
                q.push(v[i].second);
                ++i;
            }
            if (q.empty()) {
                break;
            }
            int w = q.top();
            q.pop();
            W += w;
            --k;
        }
        return W;
    }
};
