static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto n:nums) {
            ++count[n];
        }
        unordered_map<int, int> append;
        for (auto n:nums) {
            if (0 == count[n]) {
                continue;
            }
            if (append[n] > 0) {
                --append[n];
                ++append[n+1];
                --count[n];
            } else if (count[n+1] > 0 && count[n+2] > 0) {
                --count[n];
                --count[n+1];
                --count[n+2];
                ++append[n+3];
            } else {
                return false;
            }
        }
        return true;
    }
};
