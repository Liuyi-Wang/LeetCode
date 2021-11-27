class Solution {
public:
    int minimumBuckets(string street) {
        int house = 0, empty = 0;
        int result = 0;
        int n = street.size();
        if (street.size() >= 2) {
            if (street[0] == 'H' && street[1] == 'H') {
                return -1;
            }
            if (street[n-1] == 'H' && street[n-2] == 'H') {
                return -1;
            }
        }
        if (street[0] == 'H') {
            ++house;
        } else {
            ++empty;
        }
        for (int i = 1; i < street.size(); ++i) {
            if (street[i] == 'H') {
                ++house;
                if (i >= 2 
                    && (street[i-1] == 'H' || street[i-1] == 'h')
                    && (street[i-2] == 'H' || street[i-2] == 'h')) {
                    return -1;
                } else if (i >= 2 && street[i-2] == 'H') {
                    house -= 2;
                    empty -= 1;
                    street[i-2] = 'h';
                    street[i] = 'h';
                    ++result;
                }
            } else {
                ++empty;
            }
        }
        if (empty >= house) {
            return result + house;
        }
        return -1;
    }
};
