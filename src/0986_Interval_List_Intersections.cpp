/**
 *  Time:
 *  O(M+N)
 *  Space:
 * O(M+N)
 */
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, n1 = firstList.size(), j = 0, n2 = secondList.size();
        vector<vector<int>> result;
        while (i < n1 && j < n2) {
            int begin = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (begin <= end) {
                result.push_back({begin, end});
            }
            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
