class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int b = boxes.size()-1;
        int result = 0;
        for (int w = 0; w < warehouse.size() && b >= 0;) {
            if (warehouse[w] >= boxes[b]) {
                ++result;
                ++w;
            }
            --b;
        }
        return result;
    }
};
