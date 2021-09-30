static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int m = A[0];
        for (int i = 1; i < A.size(); ++i) {
            m = min(m, A[i]);
        }
        int sum = 0;
        while (m > 0) {
            sum += m%10;
            m /= 10;
        }
        return 0==sum%2?1:0;
    }
};
