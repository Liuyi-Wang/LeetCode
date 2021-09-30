class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfied = 0;
        int max_num = 0;
        for (int i = 0; i < X && i < customers.size(); ++i) {
            if (0 == grumpy[i]) {
                satisfied += customers[i];
                customers[i] = 0;
            }
            max_num += customers[i];
        }
        int num = max_num;
        for (int i = X; i < customers.size(); ++i) {
            if (0 == grumpy[i]) {
                satisfied += customers[i];
                customers[i] = 0;
            }
            num = num - customers[i-X] + customers[i];
            max_num = max(max_num, num);
        }
        return satisfied + max_num;
    }
};
