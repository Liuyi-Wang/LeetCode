class Solution {
public:
    string smallestSubsequence(string text) {
        vector<bool> contained(26, false);
        vector<short> counts(26, 0);
        for (auto c:text) {
            counts[c-'a']++;
        }
        string result;
        for (auto c:text) {
            counts[c-'a']--;
            if (contained[c-'a']) {
                continue;
            }
            while (result.size() != 0 &&
                   result.back() > c &&
                   counts[result.back()-'a']) {
                contained[result.back()-'a'] = false;
                result.pop_back();
            }
            contained[c-'a'] = true;
            result += c;
        }
        return result;
    }
};
