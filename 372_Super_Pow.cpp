static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int myPow(int x, int n) {
        if (0 == n) {
            return 1;
        }
        int half = myPow(x, n/2)%1337;
        int multi = half*half%1337;
        if (n%2) {
            return multi*(x%1337)%1337;
        } else {
            return multi;
        }
    }
    
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int i = 0; i < b.size(); ++i) {
            result = myPow(result, 10)*myPow(a, b[i])%1337;
        }
        return result;
    }
};
