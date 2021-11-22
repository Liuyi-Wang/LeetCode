/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int result = 0;
        int sum = 0;
        for (int i = 0; i < plants.size(); ++i) {
            if (sum + plants[i] <= capacity) {
                sum += plants[i];
                continue;
            }
            result += i*2;
            sum = plants[i];
        }
        return result+plants.size();
    }
};
