static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0;
        for (; l < seats.size(); ++l) {
            if (1 == seats[l]) {
                break;
            }
        }
        int r = seats.size()-1;
        for (; r >= 0; --r) {
            if (1 == seats[r]) {
                break;
            }
        }
        int result = max(l, static_cast<int>(seats.size())-1-r);
        if (l == r) {
            return result;
        }
        for (int i = l+1; i <= r; ++i) {
            if (1 == seats[i]) {
                result = max(result, (i-l)/2);
                l = i;
            }
        }
        return result;
    }
};
