/*
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bitMask0 = 0;
        for (auto num:nums) {
            bitMask0 ^= num;
        }
        long diff = bitMask0&(-bitMask0);
        long bitMask1 = 0;
        for (auto num:nums) {
            if ((num&diff) != 0) {
                bitMask1 ^= num;
            }
        }
        return {(int)bitMask1, (int)(bitMask0^bitMask1)};
    }
};
