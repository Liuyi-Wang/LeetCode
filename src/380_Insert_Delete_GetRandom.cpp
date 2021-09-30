static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) == hash.end()) {
            nums.push_back(val);
            hash[val] = nums.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) == hash.end()) {
            return false;
        }
        int i = hash[val];
        hash.erase(hash.find(val));
        swap(nums.back(), nums[i]);
        nums.pop_back();
        if (i < nums.size()) {
            hash[nums[i]] = i;
        }    
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand()%nums.size();
        return nums[i];
    }
    
private:
    unordered_map<int, int> hash;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
