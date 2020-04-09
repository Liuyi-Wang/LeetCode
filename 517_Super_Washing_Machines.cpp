class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for (auto m:machines) {
            sum += m;
        }
        if ((sum/machines.size())*machines.size() != sum) {
            return -1;
        }
        int target = sum/machines.size();
        int acc = 0;
        int result = INT_MIN;
        for (int i = 0; i < machines.size(); ++i) {
            acc += machines[i]-target;
            result = max(result, max(abs(acc), machines[i]-target));
        }
        return result;
    }
};
