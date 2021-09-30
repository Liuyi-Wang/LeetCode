static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct greater_than {
        bool inline operator() (const pair<int, int> &p1,
                                const pair<int, int> &p2) {
            return p1.first < p2.first;
        }    
    };
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater_than> q;
        for (int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
        }
        vector<string> result(nums.size(), "");
        result[q.top().second] = "Gold Medal";
        q.pop();
        if (!q.empty()) {
            result[q.top().second] = "Silver Medal";
            q.pop();
        }
        if (!q.empty()) {
            result[q.top().second] = "Bronze Medal";
            q.pop();
        }
        if (!q.empty()) {
            for (int i = 4; i <= nums.size(); ++i) {
                result[q.top().second] = to_string(i);
                q.pop();
            }
        }
        return result;
    }
};
