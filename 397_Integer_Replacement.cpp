static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int integerReplacement(int n) {
        if (1 == n) {
            return 0;
        }
        if (0 == n%2) {
            return 1+integerReplacement(n/2);
        } 
        long t = n;
        return 2+min(integerReplacement((t+1)/2), integerReplacement((t-1)/2));
    }
};
