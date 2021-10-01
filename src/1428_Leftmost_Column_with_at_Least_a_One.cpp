/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int m = d[0], n = d[1];
        int result = -1;
        for (int i = 0; i < m; ++i) {
            int l = binarySearch(binaryMatrix, i, result, n);
            if (l != -1) {
                result = l;
            }
        }
        return result;
    }
    
    int binarySearch(BinaryMatrix &binaryMatrix, int i, int r, int n) {
        if (r == -1) {
            r = n-1;
        }
        int l = 0;
        while (l+1 < r) {
            int mid = l+(r-l)/2;
            if (binaryMatrix.get(i, mid) == 1) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (binaryMatrix.get(i, l) == 1) {
            return l;
        }
        if (binaryMatrix.get(i, r) == 1) {
            return r;
        }
        return -1;
    }
};
