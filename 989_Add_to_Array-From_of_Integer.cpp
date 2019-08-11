class Solution {
public:
    vector<int> intToA(int i) {
        vector<int> result;
        while (i > 0) {
            int d = i%10;
            i /= 10;
            result.push_back(d);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> k = intToA(K);
        if (A.size() < k.size()) {
            vector<int> tmp = A;
            A = k;
            k = tmp;
        }
        int carry = 0;
        for (int i = 0; i < k.size(); ++i) {
            int sum = carry+A[A.size()-1-i]+k[k.size()-1-i];
            carry = sum/10;
            A[A.size()-1-i] = sum%10;
        }
        for (int i = 0; i < A.size()-k.size(); ++i) {
            int sum = carry+A[A.size()-k.size()-1-i];
            carry = sum/10;
            A[A.size()-k.size()-1-i] = sum%10;
        }
        if (0 == carry) {
            return A;
        }
        vector<int> result(1, carry);
        result.insert(result.end(), A.begin(), A.end());
        return result;
    }
};
