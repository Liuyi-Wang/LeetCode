class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int b = boxes.size()-1;
        int result = 0;
        for (int w1 = 0, w2 = warehouse.size()-1; w1 <= w2 && b >= 0;) {
            if (warehouse[w1] >= boxes[b]) {
                ++result;
                ++w1;
            } else if (warehouse[w2] >= boxes[b]) {
                ++result;
                --w2;
            }
            --b;
        }
        return result;
    }
};
