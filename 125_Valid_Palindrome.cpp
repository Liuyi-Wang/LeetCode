class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, tail = s.size()-1;
        while (head < tail) {
            if (!isalpha(s[head]) && !isdigit(s[head])) {
                ++head;
                continue;
            } else if (!isalpha(s[tail]) && !isdigit(s[tail])) {
                --tail;
                continue;
            }
            if (toupper(s[head]) != toupper(s[tail])) {
                return false;
            }
            ++head;
            --tail;
        }
        return true;
    }
};
