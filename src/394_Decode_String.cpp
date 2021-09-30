static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string decodeString(string s) {
        if (0 == s.size()) {
            return s;
        }
        string result;
        int l = 0;
        for (int i = 0; i < s.size();) {
            while (isdigit(s[i])) {
                ++i;
            }
            int k = 1;
            if (l != i) {
                k = atoi(s.substr(l, i-l).c_str());
            }
            if (l == i) {
                result += s[i];
                ++i;
            } else {
                int count = 1;
                ++i;
                l = i;
                while (0 != count) {
                    if ('[' == s[i]) {
                        ++count;
                    } else if (']' == s[i]) {
                        --count;
                    }
                    ++i;
                }
            }
            if (i-1-l > 0) {
                string str = decodeString(s.substr(l, i-1-l));
                for (int j = 0; j < k; ++j) {
                    result += str; 
                }
            }
            l = i;
        }
        return result;
    }
};
