static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0;
        for (int i = 0; i < A[0].size(); ++i) {
            for (int j = 1; j < A.size(); ++j) {
                if (A[j-1][i] > A[j][i]) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
