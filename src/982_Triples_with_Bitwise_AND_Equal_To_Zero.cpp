class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> counts;
        for (auto a:A) {
            for (auto b:A) {
                ++counts[a&b];
            }        
        }
        int result = 0;
        for (auto a:A) {
            for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
                if (0 == (a & it->first) ) {
                    result += it->second;
                }
            }
        }
        return result;
    }
};
