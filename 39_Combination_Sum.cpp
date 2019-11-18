static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<int> &candidates, const int &target, int i, int &sum, vector<int> &v) {
        if (target == sum) {
            d_result.push_back(v);
            return;
        }
        if (target < sum) {
            return;
        }
        for (int j = i; j < candidates.size(); ++j) {
            if (sum+candidates[j] > target) {
                continue;
            }
            v.push_back(candidates[j]);
            sum += candidates[j];
            solve(candidates, target, j, sum, v);
            sum -= candidates[j];
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        int sum = 0;
        vector<int> v;
        solve(candidates, target, 0, sum, v);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
