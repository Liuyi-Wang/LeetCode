static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        d_v.push_back(val);
        d_m[val].insert(d_v.size()-1);
        return d_m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (d_m.find(val) == d_m.end()) {
            return false;
        }
        int i = *d_m[val].begin();
        d_m[val].erase(d_m[val].begin());
        if (d_m[val].empty()) {
            d_m.erase(d_m.find(val));
        }
        if (i != d_v.size()-1) {
            d_v[i] = d_v.back();
            d_m[d_v.back()].erase(d_m[d_v.back()].find(d_v.size()-1));
            d_m[d_v.back()].insert(i);
        }
        d_v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return d_v[rand()%d_v.size()];
    }
    
private:
    vector<int> d_v;
    unordered_map<int, unordered_set<int>> d_m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
