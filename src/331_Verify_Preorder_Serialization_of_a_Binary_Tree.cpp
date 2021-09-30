static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ",";
        int count = 0;
        int i = 0;
        for (; i < preorder.size(); ++i) {
            if (',' != preorder[i]) {
                continue;
            }
            if ('#' == preorder[i-1]) {
                --count;
            } else {
                ++count;
            }
            if (count < 0) {
                break;
            }
        }
        return i==(preorder.size()-1); 
    }
};
