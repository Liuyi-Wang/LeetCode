static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size()-1;
        while (l < r) {
            if (num[l] == num[r]) {
                if ('0' != num[l] && '1' != num[l] && '8' != num[l]){
                    return false;
                }
            } else {
                if (!('6' == num[l] && '9' == num[r]) && !('9' == num[l] && '6' == num[r])) {
                    return false;
                }
            }
            ++l;
            --r;
        }
        if (l == r) {
            if ('0' != num[l] && '1' != num[l] && '8' != num[l]){
                return false;
            }
        }
        return true;
    }
};
