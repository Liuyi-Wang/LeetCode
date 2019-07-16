class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> counts(10001, 0);
        int max_count = INT_MIN, max_code = 1;
        for (auto barcode:barcodes) {
            max_count = max(max_count, ++counts[barcode]);
            if (max_count == counts[barcode]) {
                max_code = barcode;
            }
        }
        int index = 0;
        while (counts[max_code]--) {
            barcodes[index] = max_code;
            index = index+2 < barcodes.size() ? index+2 : 1;
        }
        for (int i = 1; i <= 10000; ++i) {
            while (counts[i]-- > 0) {
                barcodes[index] = i;
                index = index+2 < barcodes.size() ? index+2 : 1;
            }
        }
        return barcodes;
    }
};
