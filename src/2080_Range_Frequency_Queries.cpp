/**
 *  Time:
 *  O(Q*logN)
 *  Space:
 *  O(N)
 */
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        d_hash = vector<vector<int>>(10001, vector<int>());
        for (int i = 0; i < arr.size(); ++i) {
            d_hash[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int>::iterator begin = lower_bound(d_hash[value].begin(), d_hash[value].end(), left);
        if (begin == d_hash[value].end()) {
            return 0;
        }
        vector<int>::iterator end = upper_bound(d_hash[value].begin(), d_hash[value].end(), right);
        if (end == d_hash[value].begin()) {
            return 0;
        }
        --end;
        return end-begin+1;
    }
    
private:
    vector<vector<int>> d_hash;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
