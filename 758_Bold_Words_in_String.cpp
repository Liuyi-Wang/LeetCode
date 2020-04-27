static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<bool> b(S.size(), false);
        int end = -1;
        /*
        for (int i = 0; i < S.size(); ++i) {
            for (const auto &w:words) {
                if (i+w.size() <= S.size() && w == S.substr(i, w.size())) {
                    end = max(end, i+static_cast<int>(w.size())-1);
                }
            } 
            b[i] = i<=end;
        }*/
        for (const auto &w:words) {
            string::size_type i = S.find(w);
            while (i != string::npos) {
                for (int j = 0; j < w.size(); ++j) {
                    b[i+j] = true;
                }
                i = S.find(w, i+1);
            }
        }
        string result;
        bool bold = false;
        for (int i = 0; i < S.size(); ++i) {
            if (b[i] && !bold) {
                bold = true;
                result += "<b>";
            } else if (!b[i] && bold) {
                bold = false;
                result += "</b>";
            }
            result += S[i];
        }
        if (bold) {
            result += "</b>";
        }
        return result;
    }
};
