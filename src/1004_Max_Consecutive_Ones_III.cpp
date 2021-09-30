static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int k = 0, l = 0, r = 0;
        int result = 0;
        while (r < A.size()) {
            if (1 == A[r]) {
                ++r;
                continue;
            }
            if (k < K) {
                ++k;
                ++r;
                continue;
            }
            result = max(result, r-l);
            while (1 == A[l]) {
                ++l;
            }
            ++l;
            ++r;
        }
        result = max(result, r-l);
        return result;
    }
};
