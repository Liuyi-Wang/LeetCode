class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> flips;
        int n = A.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            while (!flips.empty() && flips.front() < i+1-K) {
                flips.pop();
            }
            if (A[i] == flips.size()%2) {
                if (n-i < K) {
                    return -1;
                }
                ++result;
                flips.push(i);
            }
        }
        return result;
    }
};
