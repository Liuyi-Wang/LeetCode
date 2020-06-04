static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(string s, int l, int& result, const string& low, const string& high) {
        if (s.size() == l) {
            if (l != 1 && s[0] == '0') {
                return;
            }
            if ((s.size() == low.size() && s.compare(low) < 0) || 
                (s.size() == high.size() && s.compare(high) > 0)) {
                return;
            }
            ++result;
            return;
        }
        solve("0"+s+"0", l, result, low, high);
        solve("1"+s+"1", l, result, low, high);
        solve("8"+s+"8", l, result, low, high);
        solve("6"+s+"9", l, result, low, high);
        solve("9"+s+"6", l, result, low, high);
    }
    
    int strobogrammaticInRange(string low, string high) {
        int result = 0;
        for (int l = low.size(); l <= high.size(); ++l) {
            if (l%2 == 0) {
                solve("", l, result, low, high);
            } else {
                solve("0", l, result, low, high);
                solve("1", l, result, low, high);
                solve("8", l, result, low, high);
            }
        }
        return result;
    }
};
