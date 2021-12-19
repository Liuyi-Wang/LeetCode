/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0;
        int l = 1;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] == prices[i-1]-1) {
                ++l;
                continue;
            }
            result += sum(l);
            l = 1;
        }
        result += sum(l);
        return result;
    }
    
    long long sum(long long n) {
        long long result = (1+n)*n/2;
        return result;
    }
};
