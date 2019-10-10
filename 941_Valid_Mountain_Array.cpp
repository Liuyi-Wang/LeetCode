static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        int i = 1;
        for (; i < A.size(); ++i) {
            if (A[i-1] >= A[i]) {
                break;
            }
        }
        if (1 == i || i == A.size()) {
            return false;
        }
        for (; i < A.size(); ++i) {
            if (A[i-1] <= A[i]) {
                return false;
            }
        }
        return true;
    }
};
