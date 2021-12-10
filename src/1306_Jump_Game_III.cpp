/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited = vector<bool>(n, false);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) {
                return true;
            }
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            if (i-arr[i] >= 0 && !visited[i-arr[i]]) {
                q.push(i-arr[i]);
            }
            if (i+arr[i] < n && !visited[i+arr[i]]) {
                q.push(i+arr[i]);
            }
        }
        return false;
    }
};
