static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for (int i = 0; i < chips.size(); ++i) {
            if (0 == chips[i]%2) {
                ++even;
            } else {
                ++odd;
            }
        }
        return min(even, odd);
    }
};
