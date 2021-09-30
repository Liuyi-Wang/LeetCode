class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> hash;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                hash[nums[i]+nums[j]].push_back(pair<int, int>(i, j));
            }
        }
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (hash.find(target-nums[i]-nums[j]) == hash.end()) {
                    continue;
                }
                for (auto p:hash[target-nums[i]-nums[j]]) {
                    if (j < p.first) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[p.first]);
                        v.push_back(nums[p.second]);
                        s.insert(v);
                    }    
                }
            }
        }
        vector<vector<int>> result;
        for (set<vector<int>>::iterator it = s.begin(); it != s.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};
