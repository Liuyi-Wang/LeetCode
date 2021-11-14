class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.size() == 0) {
            return encodedText;
        }
        int l = encodedText.size();
        int cols = l/rows;
        int end = cols-1;
        //cout << l << endl;
        while (end < l && encodedText[end] == ' ') {
            end += cols;
        }
        end -= cols;
        //cout << end << endl;
        string result;
        bool stop = false;
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows && j+i < cols; ++j) {
                //cout << i << ',' << j << '=' << cols*j+j+i << endl;
                result += encodedText[cols*j+j+i];
                if (cols*j+j+i == end) {
                    stop = true;
                }
            }
            if (stop) {
                
                break;
            }
        }
        int space = result.size()-1;
        for (; space >= 0; --space) {
            if (result[space] != ' ') {
                break;
            }
        }
        return result.substr(0, space+1);
    }
};
