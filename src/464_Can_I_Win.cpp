static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool solve(int used, const int &maxChoosableInteger, int n, int left) {
        if (0 == left) {
            return false;
        }
        if (d_hash.find(used) != d_hash.end()) {
            return d_hash[used];
        }
        int i = maxChoosableInteger;
        for (; i > 0; --i) {
            if (used & (1<<i)) {
                continue;
            }
            if (i >= n) {
                d_hash[used] = true;
                return true;
            }
            break;
        }
        for (; i > 0; --i) {
            if (used & (1<<i)) {
                continue;
            }
            if (!solve(used|(1<<i), maxChoosableInteger, n-i, left-1)) {
                d_hash[used] = true;
                return true;
            }   
        }
        d_hash[used] = false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) {
            return false;
        }
        return solve(0, maxChoosableInteger, desiredTotal, maxChoosableInteger);
    }
    
private:
    unordered_map<int, bool> d_hash;
};
