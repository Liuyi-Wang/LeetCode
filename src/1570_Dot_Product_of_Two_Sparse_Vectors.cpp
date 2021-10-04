class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                d_v.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        int i = 0, j = 0;
        while (i < d_v.size() && j < vec.d_v.size()) {
            if (d_v[i].first == vec.d_v[j].first) {
                result += d_v[i].second*vec.d_v[j].second;
                ++i;
                ++j;
            } else if (d_v[i].first > vec.d_v[j].first) {
                ++j;
            } else {
                ++i;
            }
        }
        return result;
    }

    vector<pair<int, int>> d_v;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
