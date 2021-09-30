static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (E >= C || G <= A || F >= D || H <= B) {
            return (C-A)*(D-B)+(G-E)*(H-F);
        }
        int a = max(A, E), b = max(B, F), c = min(C, G), d = min(D, H);
        long r1 = (C-A)*(D-B);
        long r2 = (G-E)*(H-F);
        return r1+r2-(c-a)*(d-b);
    }
};
