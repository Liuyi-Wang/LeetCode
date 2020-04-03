static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int solve(int m, int n, int i, int j, int l, int visited) {
        if (l > n) {
            return 0;
        }
        int result = 0;
        if (l >= m) {
            ++result;
        }
        visited += (1 << (i*3+j));
        for (int I = 0; I < 3; ++I) {
            for (int J = 0; J < 3; ++J) {
                if (visited & (1 << (I*3+J))) {
                    continue;
                }
                int ii = i+I, jj = j+J;
                if (ii%2 || jj%2 || (visited & (1 << (ii/2*3+jj/2)))) {
                    result += solve(m, n, I, J, l+1, visited);
                }
            }
        }
        return result;
    }
    
    int numberOfPatterns(int m, int n) {
        int result = 0;
        result += solve(m, n, 0, 0, 1, 0)*4;
        result += solve(m, n, 0, 1, 1, 0)*4;
        result += solve(m, n, 1, 1, 1, 0);
        return result;
    }
};
