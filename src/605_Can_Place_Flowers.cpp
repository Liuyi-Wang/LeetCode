class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (0 == n) {
            return true;
        }
        if (0 == flowerbed.size()) {
            return false;
        }
        if (1 == flowerbed.size()) {
            return 0 == flowerbed[0] && 1 == n;
        }
        if (0 == flowerbed[0] && 0 == flowerbed[1]) {
            flowerbed[0] = 1;
            --n;
        }
        if (0 == flowerbed[flowerbed.size()-1] && 0 == flowerbed[flowerbed.size()-2]) {
            flowerbed[flowerbed.size()-1] = 1;
            --n;
        }
        for (int i = 1; i < flowerbed.size()-1 && n > 0; ++i) {
            if (1 == flowerbed[i]) {
                continue;
            }
            if (0 == flowerbed[i-1] && 0 == flowerbed[i+1]) {
                --n;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
