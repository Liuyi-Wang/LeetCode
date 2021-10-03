class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (auto operation:operations) {
            if (operation[1] == '+') {
                ++result;
            } else {
                --result;
            }
        }
        return result;
    }
};
