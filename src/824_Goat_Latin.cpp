class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string w;
        int n = 1;
        string result;
        while (ss >> w) {
            string s;
            if (w[0] == 'a' ||
                w[0] == 'e' ||
                w[0] == 'i' ||
                w[0] == 'o' ||
                w[0] == 'u' ||
                w[0] == 'A' ||
                w[0] == 'E' ||
                w[0] == 'I' ||
                w[0] == 'O' ||
                w[0] == 'U'){
                s = w+"ma";
            } else {
                s = w.substr(1, w.size()-1);
                s += w[0];
                s += "ma";
            }
            result += s+string(n, 'a')+" ";
            ++n;
        }
        return result.substr(0, result.size()-1);
    }
};
