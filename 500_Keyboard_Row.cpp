class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> result;
        for (const auto& w:words) {
            set<char> row;
            if (row1.find(tolower(w[0])) != row1.end()) {
                row = row1;
            } else if (row2.find(tolower(w[0])) != row2.end()) {
                row = row2;
            } else {
                row = row3;
            }
            bool valid = true;
            for (int i = 1; i < w.size(); ++i) {
                if (row.find(tolower(w[i])) == row.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(w);
            }
        }
        return result;
    }
};
