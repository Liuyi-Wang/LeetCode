class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int result = 0;
        int sum = 0;
        for (int i = 0; i < gas.size();) {
            tank += gas[i]-cost[i];
            sum += gas[i]-cost[i];
            ++i;
            if (tank < 0) {
                tank = 0;
                result = i;
            }
        }
        return sum<0?-1:result;
    }
};
