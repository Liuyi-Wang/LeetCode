static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ar = A.size();
        int ac = A[0].size();
        int br = B.size();
        int bc = B[0].size();
        vector<vector<int>> result(ar, vector<int>(bc, 0));
        for (int i = 0; i < ar; ++i) {
            for (int j = 0; j < ac; ++j) {
                if (0 == A[i][j]) {
                    continue;
                }
                for (int k = 0; k < bc; ++k) {
                    if (0 == B[j][k]) {
                        continue;
                    }
                    result[i][k] += A[i][j]*B[j][k];
                }
            }
        }
        return result;
    }
};
