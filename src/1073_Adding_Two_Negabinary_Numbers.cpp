class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int max_len = max(arr1.size(), arr2.size());
        vector<int> added(max_len, 0);
        int digit = 0;
        for (int i = 0; i < arr1.size() && i < arr2.size(); ++i) {
            int sum = digit + arr1[arr1.size()-1-i] + arr2[arr2.size()-1-i];
            if (sum == -1) {
                added[added.size()-1-i] = 1;
                digit = 1;
            } else if (sum == 0) {
                digit = 0;
            } else if (sum == 1) {
                added[added.size()-1-i] = 1;
                digit = 0;
            } else if (sum == 2) {
                digit = -1;
            } else if (sum == 3) {
                added[added.size()-1-i] = 1;
                digit = -1;
            }
        }
        if (arr1.size() > arr2.size()) {
            for (int i = arr2.size(); i < arr1.size(); ++i) {
                int sum = digit + arr1[arr1.size()-1-i];
                if (sum == -1) {
                    added[added.size()-1-i] = 1;
                    digit = 1;
                } else if (sum == 0) {
                    digit = 0;
                } else if (sum == 1) {
                    added[added.size()-1-i] = 1;
                    digit = 0;
                } else if (sum == 2) {
                    digit = -1;
                } else if (sum == 3) {
                    added[added.size()-1-i] = 1;
                    digit = -1;
                }
            }
        } else if (arr1.size() < arr2.size()) {
            for (int i = arr1.size(); i < arr2.size(); ++i) {
                int sum = digit + arr2[arr2.size()-1-i];
                if (sum == -1) {
                    added[added.size()-1-i] = 1;
                    digit = 1;
                } else if (sum == 0) {
                    digit = 0;
                } else if (sum == 1) {
                    added[added.size()-1-i] = 1;
                    digit = 0;
                } else if (sum == 2) {
                    digit = -1;
                } else if (sum == 3) {
                    added[added.size()-1-i] = 1;
                    digit = -1;
                }
            }
        }
        if (digit == -1) {
            vector<int> result(2, 1);
            result.insert(result.end(), added.begin(), added.end());
            return result;
        } else if (digit == 1) {
            vector<int> result(1, 1);
            result.insert(result.end(), added.begin(), added.end());
            return result;
        }
        int leading_zero = -1;
        for (int i = 0; i < added.size(); ++i) {
            if (added[i] == 0) {
                leading_zero = i;
            } else {
                break;
            }
        }
        if (leading_zero != -1) {
            vector<int>::const_iterator head = added.begin()+leading_zero+1;
            vector<int>::const_iterator tail = added.end();
            vector<int> result(head, tail);
            if (result.size() == 0) {
                result.push_back(0);
            }
            return result;
        }
        return added;
    }
};
