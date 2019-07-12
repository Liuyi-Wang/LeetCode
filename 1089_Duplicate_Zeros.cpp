class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        unsigned int len = 0;
        int index = 0;
        bool oneZero = false;
        for (; index < arr.size(); ++index) {
            if (0 == arr[index]) {
                len += 2;
            } else {
                len++;
            }
            if (len == arr.size()) {
                break;
            }
            if (len > arr.size()) {
                oneZero = true;
                break;
            }
        }
        len = arr.size()-1;
        if (0 == arr[index] && oneZero) {
            arr[len--] = 0;
            index--;
        }
        while (index >= 0) {
            if (0 == arr[index]) {
                arr[len] = 0;
                arr[len-1] = 0;
                len -= 2;
                index--;
            } else {
                arr[len--] = arr[index--];
            }
        }
    }
};
