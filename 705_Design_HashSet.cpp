static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        d_hash = vector<bool>(1000000, false);
    }
    
    void add(int key) {
        d_hash[key] = true;
    }
    
    void remove(int key) {
        d_hash[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return d_hash[key];
    }

private:
    vector<bool> d_hash;
};

