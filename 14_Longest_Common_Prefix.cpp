static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (0 == strs.size()) {
            return "";
        }
        if (1 == strs.size()) {
            return strs[0];
        }
        string result;
        int index = 0;
        while (index < strs[0].size()) {
            bool valid = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (index >= strs[i].size() || strs[0][index] != strs[i][index]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result += strs[0][index];
            } else {
                break;
            }
            ++index;
        }
        return result;
    }
};
