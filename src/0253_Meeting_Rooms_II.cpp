/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> heap;
        int result = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            while (!heap.empty() && heap.top() <= intervals[i][0]) {
                heap.pop();
            }
            heap.push(intervals[i][1]);
            result = max(result, (int)heap.size());
        }
        return result;
    }
};
