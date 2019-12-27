class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int diff = (arr.back()-arr[0])/(int(arr.size()));
        for (int i = 1; i < arr.size(); ++i) {
            if (diff == arr[i]-arr[i-1]) {
                continue; 
            }
            return arr[i-1]+diff;
        }
        return arr.back();
    }
};
