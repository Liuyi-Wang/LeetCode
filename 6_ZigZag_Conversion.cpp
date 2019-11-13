class Solution {
public:
    string convert(string s, int numRows) {
        string result = s;
        int block = max(1, numRows*2-2);
        int index = 0;
        for (int i = 0; i < numRows; ++i) {
            if (0 == i || numRows-1 == i) {
                int begin = i;
                while(begin < s.size()) {
                    result[index++] = s[begin];
                    begin += block;
                }
            } else {
                int begin = i;
                while(begin < s.size()) {
                    result[index++] = s[begin];
                    if (begin+(numRows-1-i)*2 < s.size()) {
                        result[index++] = s[begin+(numRows-1-i)*2];
                    }
                    begin += block;
                }
                
            }
        }
        return result;
    }
};
