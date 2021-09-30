class PhoneDirectory {
public:
    struct Node {
        int d_v;
        Node *prev;
        Node *next;
        Node(int v): d_v(v), prev(NULL), next(NULL) {}
    };
    
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        m = maxNumbers;
        first = true;
        i = 0;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (s.size() == m) {
            return -1;
        }
        if (first) {
            int result = i;
            s.insert(i++);
            if (i == m) {
                first = false;
            }
            return result;
        }
        int result = number();
        pop();
        s.insert(result);
        return result;
        /*
        int result = q.front();
        q.pop();
        s.insert(result);
        return result;*/
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return s.find(number) == s.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (s.find(number) != s.end()) {
            s.erase(s.find(number));
            push(number);
            //q.push(number);
        }
    }

private:
    Node *head;
    Node *tail;
    unordered_set<int> s;
    int m;
    bool first;
    int i;
    queue<int> q;
    
    int number() {
        return head->next->d_v;
    }
    
    void pop() {
        Node *node = head->next;
        head->next = node->next;
        node->next->prev = head;
        delete node;
    }
    
    void push(int number) {
        Node *node = new Node(number);
        node->next = tail;
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
