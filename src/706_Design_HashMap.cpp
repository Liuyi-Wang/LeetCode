static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        d_hash = vector<int>(1000000, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        d_hash[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return d_hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        d_hash[key] = -1;
    }
    
private:
    vector<int> d_hash;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
