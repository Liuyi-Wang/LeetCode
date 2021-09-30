static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto n:nums) {
            ++count[n];
        }
        vector<vector<int>> bucket(nums.size()+1, vector<int>());
        for (unordered_map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
            bucket[it->second].push_back(it->first);
        }
        vector<int> result(k, 0);
        int index = 0;
        for (int i = bucket.size()-1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                result[index++] = bucket[i][j];
                if (index == k) {
                    break;
                }
            }
            if (index == k) {
                break;
            }
        }
        return result;
    }
};
