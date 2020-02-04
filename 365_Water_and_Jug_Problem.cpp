class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return 0 == z || (x+y >= z && z%gcd(x, y) == 0);
    }
    
    int gcd(int x, int y) {
        return 0 == y?x:gcd(y, x%y);
    }
};
