class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int n = nums.size();
        set<int> s;
        for (auto num:nums) {
            s.insert(num);
        }
        vector<int> v(s.begin(), s.end());
        int begin = 0;
        int end = 0;
        int result = n;
        for (; begin < v.size()-1 && end < v.size()-1; ++begin) {
            int target = v[begin]+n-1;
            int i = lowerBound(v, begin+1, target);
            if (i == -1) {
                end = v.size()-1;
            } else if (v[i] == target) {
                end = i;
            } else {
                end = i-1;
            }
            int len = end-begin+1;
            result = min(result, n-len);
        }
        return result;
    }
    
    int lowerBound(const vector<int>& v, int l, int target) {
        int r = v.size()-1;
        while (l+1 < r) {
            int mid = l+(r-l)/2;
            if (v[mid] == target) {
                return mid;
            } else if (v[mid] > target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (v[l] >= target) {
            return l;
        }
        if (v[r] >= target) {
            return r;
        }
        return -1;
    }
};
