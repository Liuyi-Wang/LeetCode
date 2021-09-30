class Solution {
public:
    string similarRGB(string color) {
        unordered_map<char, int> dict;
        for (int i = 0; i < 16; ++i) {
            if (i <= 9) {
                dict['0'+i] = i;
            } else {
                dict['a'+i-10] = i;
            }
        }
        string result = "#";
        for (int i = 1; i < color.size(); i += 2) {
            int d1 = dict[color[i]];
            int d2 = dict[color[i+1]];
            if (d1 == d2) {
                result += color.substr(i, 2);
            } else if (d1 < d2) {
                if (d2-d1 < 16+d1+1-d2) {
                    string s(2, color[i]);
                    result += s;
                } else {
                    string s(2, color[i]=='9'?'a':(color[i]+1));
                    result += s;
                }
            } else {
                if (d1-d2 < 16+d2-(d1-1)) {
                    string s(2, color[i]);
                    result += s;
                } else {
                    string s(2, color[i]=='a'?'9':(color[i]-1));
                    result += s;
                }
            }
        }
        return result;
    }
};
