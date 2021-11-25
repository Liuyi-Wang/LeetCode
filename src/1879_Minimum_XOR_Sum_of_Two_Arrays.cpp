/**
 *  Time:
 *  O()
 *  Space:
 *  O(2^n)
 */
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() > v2.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0, 0});
        vector<bool> visited(1<<n2, false);
        while (!heap.empty()) {
            int state = heap.top()[0];
            int i1 = heap.top()[1];
            int sum = heap.top()[2];
            heap.pop();
            if (i1 == n1) {
                return sum;
            }
            if (visited[state]) {
                continue;
            }
            visited[state] = true;
            for (int i2 = 0; i2 < n2; ++i2) {
                if ((1<<i2)&state) {
                    continue;
                }
                int newState = (1<<i2)|state;
                if (visited[newState]) {
                    continue;
                }
                heap.push({newState, i1+1, sum+(nums1[i1]^nums2[i2])});
            }
        }
        return -1;
    }
};
