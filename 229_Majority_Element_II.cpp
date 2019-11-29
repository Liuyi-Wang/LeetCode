static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (0 == nums.size()) {
            return result;
        }
        int n1 = nums[0], c1 = 1;
        int n2;
        int c2 = 1;
        int i = 1;
        for (; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                ++c1;
            } else {
                n2 = nums[i];
                break;
            }
        }
        if (i == nums.size()) {
            result.push_back(n1);
            return result;
        }
        ++i;
        for (; i < nums.size(); ++i) {
            if (nums[i] == n1) {
                ++c1;
            } else if (nums[i] == n2) {
                ++c2;
            } else if (0 == c1) {
                n1 = nums[i];
                c1 = 1;
            } else if (0 == c2) {
                n2 = nums[i];
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == n1) {
                ++c1;
            }
            if (nums[i] == n2) {
                ++c2;
            }
        }
        if (c1 > nums.size()/3) {
            result.push_back(n1);
        }
        if (c2 > nums.size()/3) {
            result.push_back(n2);
        }
        return result;
    }
};
