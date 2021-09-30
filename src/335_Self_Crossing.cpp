static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() >= 4 && x[3] >= x[1] && x[0] >= x[2]) {
            return true;
        }
        if (x.size() >= 5 && x[4] >= x[2] && x[1] >= x[3]) {
            return true;
        }
        if (x.size() >= 5 && x[2] <= x[4]+x[0] && x[3] == x[1]) {
            return true;
        }
        for (int i = 5; i < x.size(); ++i) {
            if (x[i-3] >= x[i-1] && x[i] >= x[i-2]) {
                return true;
            }
            if (x[i-2] <= x[i]+x[i-4] && x[i-1] == x[i-3]) {
                return true;
            }
            if (x[i-2] >= x[i-4] && x[i-2]-x[i] <= x[i-4] && x[i-3] >= x[i-1] && x[i-3]-x[i-5] <= x[i-1]) {
                return true;
            }
        }
        return false;
    }
};
