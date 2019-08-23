class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> dict(26, 0);
        for (int i = 0; i < B.size(); ++i) {
            vector<int> temp(26, 0);
            for (const auto b:B[i]) {
                ++temp[b-'a'];
                dict[b-'a'] = max(dict[b-'a'], temp[b-'a']);
            }
        }
        vector<string> result;
        for (const auto a:A) {
            vector<int> temp(26, 0);
            for (const auto c:a) {
                ++temp[c-'a'];
            }
            bool universal = true;
            for (int i = 0; i < 26; ++i) {
                if (temp[i] < dict[i]) {
                    universal = false;
                    break;
                }
            }
            if (universal) {
                result.push_back(a);
            }
        }
        return result;
    }
};
