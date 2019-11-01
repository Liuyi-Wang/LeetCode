class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN, i = -1;
        for (auto p:preorder) {
            if (p < low) {
                return false;
            }
            while (i >= 0 && preorder[i] < p) {
                low = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};
