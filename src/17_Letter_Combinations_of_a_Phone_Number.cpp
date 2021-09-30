static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const string &digits, int i, string s) {
        if (digits.size() == i) {
            d_result.push_back(s);
            return;
        }
        string t;
        switch(digits[i]) {
            case '2':
                t = "abc";
                break;
            case '3':
                t = "def";
                break;
            case '4':
                t = "ghi";
                break;
            case '5':
                t = "jkl";
                break;
            case '6':
                t = "mno";
                break;
            case '7':
                t = "pqrs";
                break;
            case '8':
                t = "tuv";
                break;
            case '9':
                t = "wxyz";
                break;
        }
        s += 'a';
        for (int j = 0; j < t.size(); ++j) {
            s.back() = t[j];
            solve(digits, i+1, s);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (0 == digits.size()) {
            return d_result;
        }
        solve(digits, 0, "");
        return d_result;
    }
    
private:
    vector<string> d_result;
};
