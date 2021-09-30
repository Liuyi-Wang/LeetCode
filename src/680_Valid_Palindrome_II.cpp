int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
    }();

class Solution {
public:
    bool solve(const string& s, int head, int tail) {
        while (head < tail) {
            if (s[head] == s[tail]) {
                ++head;
                --tail;
                continue;
            }
            return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int head = 0, tail = s.size()-1;
        while (head < tail) {
            if (s[head] == s[tail]) {
                ++head;
                --tail;
                continue;
            }
            if (solve(s, head+1, tail) || solve(s, head, tail-1)) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};
