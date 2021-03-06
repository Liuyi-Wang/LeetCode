static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<int> &candidates, int &target, int i, vector<int> &v) {
        if (0 == target) {
            d_result.push_back(v);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int j = i; j < candidates.size(); ++j) {
            if (target < candidates[j]) {
                break;
            }
            v.push_back(candidates[j]);
            target -= candidates[j];
            solve(candidates, target, j, v);
            target += candidates[j];
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        solve(candidates, target, 0, v);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
