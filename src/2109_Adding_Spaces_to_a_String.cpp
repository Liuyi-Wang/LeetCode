/**
 *  Time:
 *  O(m)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int begin = 0;
        int i = 0;
        if (spaces[i] == 0) {
            result += " ";
            ++i;
        }
        for (; i < spaces.size(); ++i) {
            int end = spaces[i]-1;
            result += (s.substr(begin, end-begin+1) + " ");
            begin = end+1;
        }
        result += s.substr(begin);
        return result;
    }
};
