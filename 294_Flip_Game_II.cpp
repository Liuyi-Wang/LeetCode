static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canWin(string s) {
        if (d_hash.find(s) != d_hash.end()) {
            return d_hash[s];
        }
        for (int i = 1; i < s.size(); ++i) {
            if ('+' == s[i] && '+' == s[i-1]) {
                string str = s.substr(0, i-1)+"--"+s.substr(i+1);
                if (!canWin(str)) {
                    d_hash[s] = true;
                    return true;
                }
            }
        }
        d_hash[s] = false;
        return false;
    }

private:
    unordered_map<string, bool> d_hash;
};
