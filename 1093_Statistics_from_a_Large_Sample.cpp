class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double min = 256;
        for (int i = 0; i <= 255; ++i) {
            if (count[i] == 0) {
                continue;
            }
            min = i;
            break;
        }
        double max = -1;
        for (int i = 255; i >= 0; --i) {
            if (count[i] == 0) {
                continue;
            }
            max = i;
            break;
        }
        /// sum >= 1 => at least one sample
        if (min == max) {
            double a[] = {min, max, min, min, min};
            vector<double> result(a, a + sizeof(a)/sizeof(a[0]));
            return result;
        }
        ///cout << "min: " << min << " " << "max: " << max << endl;
        int counts = count[min] + count[max];
        double sum = min*count[min] + max*count[max];
        double median_left = min, median_right = max;
        int count_left = count[min], count_right = count[max];
        int begin = min, end = max;
        double mode = min;
        if (count[min] < count[max]) {
            mode = max;
        }
        while (begin < end-1) {
            if (count_left <= count_right) {
                ++begin;
                if (count[begin] == 0) {
                    continue;
                }
                counts += count[begin];
                sum += begin*count[begin];
                median_left = begin;
                count_left += count[begin];
                if (count[begin] > count[mode]) {
                    mode = begin;
                }
            } else {
                --end;
                if (count[end] == 0) {
                    continue;
                }
                counts += count[end];
                sum += end*count[end];
                median_right = end;
                count_right += count[end];
                if (count[end] > count[mode]) {
                    mode = end;
                }
            }
            /*
            cout << "counts: " << counts
                 << " sum: " << sum
                 << " median_r: " << median_right
                 << " median_l: " << median_left
                 << " c_r: " << count_right
                 << " c_l: " << count_left
                 << endl;
            */
        }
        double median = -1;
        if (count_left > count_right) {
            median = median_left;
        } else if (count_left == count_right) {
            median = (median_left + median_right)/2;
        } else if (count_left < count_right) {
            median = median_right;
        }
        double a[] = {min, max, sum/counts, median, mode};
        vector<double> result(a, a + sizeof(a)/sizeof(a[0]));
        return result;
    }
};
