/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int cur = 0;
        int result = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i];
            cur += gas[i];
            total -= cost[i];
            cur -= cost[i];
            if (cur < 0) {
                cur = 0;
                result = i+1;
            }
        }
        if (total < 0) {
            return -1;
        }
        return result;
    }
};
