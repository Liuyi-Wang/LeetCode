class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int total = arr.size();
        map<int, int> hash;
        for (auto a:arr) {
            ++hash[a];
        }
        priority_queue<int, vector<int>> heap;
        for (auto it:hash) {
            heap.push(it.second);
        }
        int result = 0;
        int count = 0;
        while (!heap.empty() && count < total/2) {
            ++result;
            count += heap.top();
            heap.pop();
        }
        return result;
    }
};
