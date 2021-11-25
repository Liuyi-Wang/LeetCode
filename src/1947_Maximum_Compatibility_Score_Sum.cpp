/**
 *  Time:
 *  O()
 *  Space:
 *  O(P(N,N)+2^N)
 */
class Solution {
public:
    int score(const vector<vector<int>>& students,
              int student,
              const vector<vector<int>>& mentors,
              int mentor) {
        int count = 0;
        for (int i = 0; i < students[student].size(); ++i) {
            if (students[student][i] != mentors[mentor][i]) {
                ++count;
            }
        }
        return count;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = mentors.size();
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() > v2.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0, 0});
        vector<int> visited(1<<n, false);
        while (!heap.empty()) {
            int state = heap.top()[0];
            int i1 = heap.top()[1];
            int sum = heap.top()[2];
            heap.pop();
            if (i1 == m) {
                return m*students[0].size()-sum;
            }
            if (visited[state]) {
                continue;
            }
            visited[state] = true;
            for (int i2 = 0; i2 < n; ++i2) {
                if ((1<<i2)&state) {
                    continue;
                }
                int newState = ((1<<i2)|state);
                if (visited[newState]) {
                    continue;
                }
                heap.push({newState, i1+1, sum+score(students, i1, mentors, i2)});
            }
        }
        return -1;
    }
};
