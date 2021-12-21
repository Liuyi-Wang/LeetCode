/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int result = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v;
            for (int j = i; j < arr.size(); j += k) {
                v.push_back(arr[j]);
            }
            result += (v.size()-LIS(v));
        }
        return result;
    }
    
    int LIS(vector<int>& v) {
        vector<int> lis;
        lis.push_back(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] >= lis.back()) {
                lis.push_back(v[i]);
                continue;
            }
            int j = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[j] = v[i];
        }
        return lis.size();
    }
};
