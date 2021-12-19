/**
 *  Time:
 *  O(mn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto word:words) {
            if (isP(word)) {
                return word;
            }
        }
        return "";
    }
    
    bool isP(const string& s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
