static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> b(s.size(), false);
        int end = -1;
        for (int i = 0; i < s.size(); ++i) {
            for (const auto &d:dict) {
                if (i+d.size() <= s.size() && s.substr(i, d.size()) == d) {
                    end = max(end, i+static_cast<int>(d.size())-1);
                }
            }
            b[i] = (i <= end);
        }
        string result;
        bool bold = false;
        for (int i = 0; i < s.size(); ++i) {
            if (b[i] && !bold) {
                bold = true;
                result += "<b>";    
            } else if (!b[i] && bold) {
                bold = false;
                result += "</b>";
            }
            result += s[i];
        }
        if (bold) {
            result += "</b>";
        }
        return result;
    }
};
