class NumArray {
public:
    NumArray(vector<int>& nums) {
        s.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            s.push_back(s.back()+nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return s[j+1] - s[i];
    }
    
private:
    vector<int> s;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
