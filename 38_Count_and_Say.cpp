static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string countAndSay(int n) {
        --n;
        string s = "1";
        while (n > 0) {
            string t;
            int count = 1;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == s[i-1]) {
                    ++count;
                } else {
                    t += to_string(count);
                    t += s[i-1];
                    count = 1;
                }
            }
            t += to_string(count);
            t += s[s.size()-1];
            s = t;
            --n;
        }
        return s;
    }
};
