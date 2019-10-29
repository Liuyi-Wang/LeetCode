static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.first < p2.first;
        }    
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || 0 == k) {
            return result;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less_than> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() < k) {
                q.push(pair<int, int>(nums[i], i));
            } else {
                result.push_back(q.top().first);
                q.push(pair<int, int>(nums[i], i));
                while (q.top().second < i-k+1) {
                    q.pop();
                }
            }
        }
        result.push_back(q.top().first);
        return result;
    }
};
