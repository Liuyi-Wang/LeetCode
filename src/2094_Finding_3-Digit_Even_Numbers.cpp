class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        set<int> result;
        int n = digits.size();
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (digits[k]%2 == 0 && digits[i]*100+digits[j]*10+digits[k] >= 100)
                        result.insert(digits[i]*100+digits[j]*10+digits[k]);
                    if (digits[j]%2 == 0 && digits[i]*100+digits[k]*10+digits[j] >= 100)
                        result.insert(digits[i]*100+digits[k]*10+digits[j]);
                    if (digits[k]%2 == 0 && digits[j]*100+digits[i]*10+digits[k] >= 100)
                        result.insert(digits[j]*100+digits[i]*10+digits[k]);
                    if (digits[i]%2 == 0 && digits[j]*100+digits[k]*10+digits[i] >= 100)
                        result.insert(digits[j]*100+digits[k]*10+digits[i]);
                    if (digits[j]%2 == 0 && digits[k]*100+digits[i]*10+digits[j] >= 100)
                        result.insert(digits[k]*100+digits[i]*10+digits[j]);
                    if (digits[i]%2 == 0 && digits[k]*100+digits[j]*10+digits[i] >= 100)
                        result.insert(digits[k]*100+digits[j]*10+digits[i]);
                    while (k+1 < n && digits[k+1] == digits[k]) {
                        ++k;
                    }
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
