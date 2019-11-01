static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyLinkedList {
public:
    struct Node {
        int d_val;
        Node* d_next;
        Node(int val) : d_val(val), d_next(NULL) {} 
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        d_head = new Node(0);
        d_tail = NULL;
        d_len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= d_len) {
            return -1;
        }
        Node* node = d_head->d_next;
        int i = 0;
        while (node) {
            if (index == i) {
                return node->d_val;
            }
            node = node->d_next;
            ++i;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->d_next = d_head->d_next;
        d_head->d_next = node;
        if (0 == d_len) {
            d_tail = node;
        }
        ++d_len;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (0 == d_len) {
            addAtHead(val);
        } else {
            Node* node = new Node(val);
            d_tail->d_next = node;
            d_tail = node;
            ++d_len;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > d_len) {
            return;
        }
        if (index == d_len) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* node = d_head->d_next;
        int i = 0;
        while (node) {
            if (index-1 == i) {
                break;
            }
            node = node->d_next;
            ++i;
        }
        Node* newNode = new Node(val);
        newNode->d_next = node->d_next;
        node->d_next = newNode;
        ++d_len;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= d_len) {
            return;
        }
        if (0 == index) {
            d_head->d_next = d_head->d_next->d_next;
            --d_len;
            if (0 == d_len) {
                d_tail = NULL;
            }
            return;
        }
        Node* node = d_head->d_next;
        int i = 0;
        while (node) {
            if (index-1 == i) {
                break;
            }
            node = node->d_next;
            ++i;
        }
        node->d_next =  node->d_next->d_next;
        --d_len;
        if (index == d_len) {
            d_tail = node;
        }
    }

private:
    Node* d_head;
    Node* d_tail;
    int d_len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
