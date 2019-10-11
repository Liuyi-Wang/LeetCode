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
            bool d = false;
            char c = A[0][i];
            for (int j = 1; j < A.size(); ++j) {
                if (d) {
                    A[j][i] = A[0][i];
                    continue;
                }
                if (A[j-1].substr(0, i+1) > A[j].substr(0, i+1)) {
                    d = true;
                }
            }
            if (d) {
                for (int j = 1; j < A.size(); ++j) {
                    A[j][i] = A[0][i];
                }
                ++result;
            }
        }
        return result;
    }
};
