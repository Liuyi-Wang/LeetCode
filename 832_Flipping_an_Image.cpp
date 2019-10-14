static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            int begin = 0, end = A[i].size()-1;
            while (begin < end) {
                int t = A[i][begin];
                A[i][begin] = 1-A[i][end];
                A[i][end] = 1-t;
                ++begin;
                --end;
            }
            if (begin == end) {
                A[i][begin] = 1-A[i][begin];
            }
        }
        return A;
    }
};
