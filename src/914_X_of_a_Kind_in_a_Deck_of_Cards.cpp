static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int gcd(int a, int b) {
        return a==0?b:gcd(b%a, a);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) {
            return false;
        }
        unordered_map<int, int> counts;
        for (auto c:deck) {
            ++counts[c];
        }
        int x = 0;
        for (auto count:counts) {
            x = gcd(count.second, x);
        }
        return x>1;
    }
};
