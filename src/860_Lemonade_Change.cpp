class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto b:bills) {
            if (5 == b) {
                ++five;
            } else if (10 == b) {
                if (0 == five) {
                    return false;
                }
                ++ten;
                --five;
            } else {
                if (ten >= 1 && five >= 1) {
                    --ten;
                    --five;
                    ++twenty;
                } else if (five >= 3) {
                    five -= 3;
                    ++twenty;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
