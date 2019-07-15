class Solution {
public:
    string solve(const string& str1, const string& str2) {
        if (str1.size() < str2.size()) {
            return solve(str2, str1);
        }
        if (str1.size() == str2.size()) {
            return (str1 == str2)?str1:"";
        }
        for (int i = 0; i < str2.size(); ++i) {
            if (str1[i] != str2[i]) {
                return "";
            }
        }
        string tail = str1.substr(str2.size());
        return solve(tail, str2);
    }
    
    string gcdOfStrings(string str1, string str2) {
        return solve(str1, str2);    
    }
};
