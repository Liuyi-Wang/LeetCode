class RandomizedSet {
public:
    RandomizedSet() {
        d_len = 0;
    }
    
    bool insert(int val) {
        if (val2i.find(val) == val2i.end()) {
            if (d_len == d_v.size()) {
                d_v.push_back(val);
            } else {
                d_v[d_len] = val;
            }
            val2i[val] = d_len++;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (val2i.find(val) != val2i.end()) {
            --d_len;
            int t = d_v[d_len];
            int i = val2i[val];
            swap(d_v[d_len], d_v[val2i[val]]);
            val2i[t] = i;
            val2i.erase(val2i.find(val));
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int r = rand();
        return d_v[r%d_len];
    }
    
private:
    vector<int> d_v;
    unordered_map<int, int> val2i;
    int d_len;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
