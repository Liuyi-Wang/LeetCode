class Solution {
public:
    struct smaller_than {
        inline bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        }
    };
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, smaller_than> heap;
        heap.push({0, nums[0]});
        for (int i = 1; i < n; ++i) {
            while (heap.top().first+k < i) {
                heap.pop();
            }
            if (i == n-1) {
                return heap.top().second+nums[i];
            }
            heap.push({i, heap.top().second+nums[i]});
        }
        return heap.top().second;
    }
};
