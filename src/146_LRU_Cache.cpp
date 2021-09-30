static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class LRUCache {
public:
    struct Node {
        int k;
        int v;
        Node *next;
        Node *prev;
        Node (int key, int value): k(key), v(value), next(NULL), prev(NULL) {}
    };
    
    LRUCache(int capacity) {
        d_capacity = capacity;
        n = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (key_node.find(key) == key_node.end()) {
            return -1;
        }
        update(key);
        return key_node[key]->v;
    }
    
    void put(int key, int value) {
        if (key_node.find(key) == key_node.end()) {
            if (n == d_capacity) {
                remove();   
                --n;
            }
            Node *node = new Node(key, value);
            key_node[key] = node; 
            insert(node);
            ++n;
        } else {
            key_node[key]->v = value;
            update(key);
        }
    }
    
private:
    Node *head;
    Node *tail;
    unordered_map<int, Node*> key_node;
    int d_capacity;
    int n;
    
    void isolate(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insert(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void update(int key) {
        Node *node = key_node[key];
        isolate(node);
        insert(node);
    }
    
    void remove() {
        key_node.erase(key_node.find(tail->prev->k));
        isolate(tail->prev);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
