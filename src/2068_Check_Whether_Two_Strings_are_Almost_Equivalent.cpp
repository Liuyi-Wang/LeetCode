class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> counts(26, 0);
        for (auto c:word1) {
            ++counts[c-'a'];
        }
        for (auto c:word2) {
            --counts[c-'a'];
        }
        for (auto count:counts) {
            if (count > 3 || count < -3) {
                return false;
            }
        }
        return true;
    }
};
