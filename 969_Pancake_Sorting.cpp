class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> st = A;
        sort(st.begin(), st.end());
        vector<int> result;
        for (int i = st.size()-1; i >= 1; --i) {
            if (A[i] == st[i]) {
                continue;
            }
            int index = 0;
            for (; index < A.size(); ++index) {
                if (A[index] == st[i]) {
                    break;
                }
            }
            if (0 != index) {
                result.push_back(index+1);
                reverse(A.begin(), A.begin()+index+1);
            }
            result.push_back(i+1);
            reverse(A.begin(), A.begin()+i+1);
        }
        return result;
    }
};
