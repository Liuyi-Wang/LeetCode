class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (1 == stones.size()) {
            return stones[0];
        }
        priority_queue<int> heap;
        for (auto i:stones) {
            heap.push(i);
        }
        while (heap.size() > 1) {
            int topFirst = heap.top();
            heap.pop();
            int topSecond = heap.top();
            heap.pop();
            if (topFirst != topSecond) {
                heap.push(topFirst-topSecond);
                continue;
            }
            if (topFirst == topSecond && heap.empty()) {
                return 0;
            }
        }
        return heap.top();
    }
};
