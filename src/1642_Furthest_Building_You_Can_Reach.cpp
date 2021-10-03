class Solution {
public:
    struct greater_than {
        inline bool operator () (int i1, int i2) {
            return i1 > i2;
        }
    };
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater_than> heap;
        int i = 0;
        for (; i < static_cast<int>(heights.size())-1; ++i) {
            if (heights[i] >= heights[i+1]) {
               continue; 
            }
            if (heap.size() < ladders) {
                heap.push(heights[i+1]-heights[i]);
                continue;
            }
            int h = heights[i+1]-heights[i];
            if (!heap.empty() && heights[i+1]-heights[i] > heap.top()) {
                heap.push(h);
                h = heap.top();
                heap.pop();
            }
            bricks -= h;
            if (bricks < 0) {
                return i;
            }
        }
        return i;
    }
};
