class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0, end = numbers.size()-1;
        vector<int> result;
        while (begin < end) {
            if (target == numbers[begin]+numbers[end]) {
                result.push_back(begin+1);
                result.push_back(end+1);
                return result;
            } else if (target > numbers[begin]+numbers[end]) {
                ++begin;
            } else {
                --end;
            }
            while (0 != begin && numbers[begin-1] == numbers[begin]) {
                ++begin;
            }
            while (numbers.size()-1 != end && numbers[end+1] == numbers[end]) {
                --end;
            }
        }
        return result;
    }
};
