/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int countPoints(string rings) {
        int result = 0;
        vector<int> v(10, 0);
        for (int i = 0; i < rings.size(); i += 2) {
            if (rings[i] == 'R') {
                v[rings[i+1]-'0'] |= 1;
            } else if (rings[i] == 'G') {
                v[rings[i+1]-'0'] |= (1<<1);
            } else if (rings[i] == 'B') {
                v[rings[i+1]-'0'] |= (1<<2);
            }
        }
        for (auto n:v) {
            if (n == 7) {
                ++result;
            }
        }
        return result;
    }
};
