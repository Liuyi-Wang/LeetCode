class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        d_parent = parent;
        d_lock = vector<int>(n, 0);
        d_children = vector<vector<int>>(n, vector<int>());
        for (int i = 1; i < n; ++i) {
            d_children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (d_lock[num] != 0) {
            return false;
        }
        d_lock[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (d_lock[num] != user) {
            return false;
        }
        d_lock[num] = 0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (d_lock[num] != 0) {
            return false;
        }
        int i = num;
        bool locked = false;
        while (i != 0) {
            i = d_parent[i];
            if (d_lock[i] != 0) {
                locked = true;
                break;
            }
        }
        if (locked) {
            return false;
        }
        if (!unlockChildren(num)) {
            return false;
        }
        d_lock[num] = user;
        return true;
    }
    
private:
    vector<int> d_lock;
    vector<vector<int>> d_children;
    vector<int> d_parent;
    
    bool unlockChildren(int num) {
        bool unlock = false;
        if (d_lock[num] != 0) {
            d_lock[num] = 0;
            unlock = true;
        }
        for (auto child:d_children[num]) {
            if (unlockChildren(child)) {
                unlock = true;
            }
        }
        return unlock;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
