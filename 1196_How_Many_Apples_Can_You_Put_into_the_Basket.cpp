class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum > 5000) {
                return i;
            }
        }
        return arr.size();
    }
};
