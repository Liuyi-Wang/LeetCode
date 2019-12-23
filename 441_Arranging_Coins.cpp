static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int arrangeCoins(int n) {
        long long l = n;
        return (sqrt(8*l+1)-1)/2;
    }
};
