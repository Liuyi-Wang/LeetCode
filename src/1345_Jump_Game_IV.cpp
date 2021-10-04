class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) {
            return 0;
        }
        int n = arr.size();
        map<int, unordered_set<int>> hash;
        vector<bool> visited(n, false);
        for (int i = 0; i < arr.size(); ++i) {
            hash[arr[i]].insert(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int j = q.front();
                q.pop();
                if (j == n-1) {
                    return count;
                }
                if (j+1 < n && !visited[j+1]) {
                    q.push(j+1);
                    visited[j+1] = true;
                }
                if (j-1 >= 0 && !visited[j-1]) {
                    q.push(j-1);
                    visited[j-1] = true;
                }
                if (hash.find(arr[j]) != hash.end()) {
                    for (auto k:hash[arr[j]]) {
                        if (k == j || visited[k]) {
                            continue;
                        }
                        q.push(k);
                        visited[k] = true;
                    }
                    hash.erase(hash.find(arr[j]));
                }
            }
            ++count;
        }
        return count;
    }
};
