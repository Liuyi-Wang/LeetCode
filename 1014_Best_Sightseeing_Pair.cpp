class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = A[0]+A[1]-1;
        int index = 1, val = A[1];
        if (A[0] > A[1]+1) {
            index = 0;
            val = A[0];
        }
        for (int i = 2; i < A.size(); ++i) {
            result = max(result, val+A[i]+index-i);
            if (A[i]+i > val+index) {
                index = i;
                val = A[i];
            }
        }
        return result;
    }
};
