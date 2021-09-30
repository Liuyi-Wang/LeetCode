static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A == B) {
            return true;
        }
        int index = 0;
        int begin;
        while (string::npos != (begin = B.find(A[0], index))) {
            bool valid = true;
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] != B[(index+i)%A.size()]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return true;
            }
            ++index;
        }
        return false;
    }
};
