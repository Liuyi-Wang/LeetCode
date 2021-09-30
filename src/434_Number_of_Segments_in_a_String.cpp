class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        stringstream ss(s);
        while (ss >> s) {
            ++result;
        }
        return result;
    }
};
