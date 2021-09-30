class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            int sum = carry+digits[i];
            digits[i] = sum%10;
            carry = sum/10;
        }
        if (carry) {
            vector<int> result(1, 1);
            result.insert(result.end(), digits.begin(), digits.end());
            return result;
        }
        return digits;
    }
};
