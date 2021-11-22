/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;
        for (int i = n-1; i > 1; --i) {
            if (colors[i] != colors[0]) {
                result = max(result, i);
                break;
            }
        }
        for (int i = 0; i < n-1; ++i) {
            if (colors[i] != colors.back()) {
                result = max(result, n-1-i);
                break;
            }
        }
        return result;
    }
};
