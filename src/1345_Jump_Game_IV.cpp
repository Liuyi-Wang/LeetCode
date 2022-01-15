/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n;) {
            int begin = i;
            hash[arr[i]].push_back(i++);
            while (i < n && arr[i] == arr[i-1]) {
                ++i;
            }
            if (begin != i-1) {
                hash[arr[i-1]].push_back(i-1);
            }
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                int i = q.front();
                q.pop();
                if (i == n-1) {
                    return step;
                }
                if (i+1 < n && !visited[i+1]) {
                    q.push(i+1);
                    visited[i+1] = true;
                }
                if (i-1 >= 0 && !visited[i-1]) {
                    q.push(i-1);
                    visited[i-1] = true;
                }
                if (hash.find(arr[i]) != hash.end()) {
                    for (auto j:hash[arr[i]]) {
                        if (!visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                    hash.erase(hash.find(arr[i]));
                }
            }
            ++step;
        }
        return step;
    }
};
