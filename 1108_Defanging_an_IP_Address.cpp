class Solution {
public:
    string defangIPaddr(string address) {
        string result(address.size()+6, ' ');
        int index = 0;
        for (int i = 0; i < address.size(); ++i) {
            if ('.' == address[i]) {
                result[index++] = '[';
                result[index++] = '.';
                result[index++] = ']';
            } else {
                result[index++] = address[i];
            }    
        }
        return result;
    }
};
