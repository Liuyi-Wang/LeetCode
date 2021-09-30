class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        int max_w = 0;
        for (auto w:weights) {
            sum += w;
            max_w = max(max_w, w);
        }
        int small = max(sum/D+((sum%D)?1:0), max_w);
        int large = sum;
        while (small < large) {
            int mid = (small+large)/2;
            int d = 0;
            int w = 0;
            for (int i = 0; i < weights.size();) {
                w += weights[i];
                if (w <= mid) {
                    ++i;
                    continue;
                }
                ++d;
                if (d >= D) {
                    break;
                }
                w = 0;
            }
            ++d;
            if (d > D) {
                small = mid+1;
            } else {
                large = mid;
            }
        }
        return small;
    }
};
