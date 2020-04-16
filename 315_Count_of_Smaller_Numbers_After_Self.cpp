static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        if (nums.size() == 1) {
            return {0};
        }
        vector<int> v;
        v.push_back(nums.back());
        vector<int> result;
        result.push_back(0);
        for (int i = nums.size()-2; i >= 0; --i) {
            int l = 0, r = static_cast<int>(v.size())-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (v[m] >= nums[i]) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            if (v[l] >= nums[i]) {
                result.push_back(l);
                v.insert(v.begin()+l, nums[i]);
            } else if (v[r] >= nums[i]) {
                result.push_back(r);
                v.insert(v.begin()+r, nums[i]);
            } else {
                result.push_back(v.size());
                v.push_back(nums[i]);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
