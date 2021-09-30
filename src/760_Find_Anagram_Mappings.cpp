class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> bI;
        for (int i = 0; i < B.size(); ++i) {
            bI[B[i]] = i;
        }
        vector<int> result(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            result[i] = bI[A[i]];
        }
        return result;
    }
};
