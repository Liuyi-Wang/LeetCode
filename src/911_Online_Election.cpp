class TopVotedCandidate {
public:
    /*
    struct Node {
        unsigned int d_c;
        int d_person;
        Node* d_p;
        Node* d_n;
        Node():d_c(0), d_p(NULL), d_n(NULL), d_person(-1) {} 
        Node(int person):d_c(0), d_p(NULL), d_n(NULL), d_person(person) {} 
        Node(unsigned int count, int person):d_c(count), d_p(NULL), d_n(NULL), d_person(person) {} 
    };*/
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        /*
        d_head = new Node(-1, INT_MIN);
        d_tail = new Node(-1, INT_MAX);
        d_head->d_n = d_tail;
        d_tail->d_p = d_head;
        */
        d_q = times;
        d_t = times;
        int high = 0;
        int hp;
        for (unsigned int i = 0; i < times.size(); ++i) {
            /*
            votePerson(persons[i]);
            d_q[i] = d_tail->d_p->d_person;
            */
            int vote = ++d_cast[persons[i]];
            if (vote >= high) {
                hp = persons[i];
                high = vote;
            }
            d_q[i] = hp;
        }
        //printList();
        //printQ();
    }
    
    int q(int t) {
        int begin = 0, end = d_t.size()-1;
        while (begin < end-1) {
            int mid = (begin+end)/2;
            if (d_t[mid] > t) {
                end = mid-1;
            } else {
                begin = mid;
            }
        }
        if (begin != end) {
            if (d_t[end] <= t) {
                begin = end;
            }
        }
        //cout << begin << endl;
        return d_q[begin];
    }
private:
    /*
    Node* d_head;
    Node* d_tail;
    unordered_map<int, Node*> d_cast;*/
    unordered_map<int, int> d_cast;
    vector<int> d_q;
    vector<int> d_t;
    /*
    void printList() {
        Node* n = d_head->d_n;
        while (n != d_tail) {
            cout << n->d_person << "," << n->d_c << "->";
            n = n->d_n;
        }
        cout << endl;
    }
    
    void printQ() {
        for (auto person:d_q) {
            cout << person << ",";
        }
        cout << endl;
    }
    
    void insertNode(Node* node) {
        d_head->d_n->d_p = node;
        node->d_n = d_head->d_n;
        d_head->d_n = node;
        node->d_p = d_head;
    }
    
    void isolateNode(Node* node) {
        node->d_p->d_n = node->d_n;
        node->d_n->d_p = node->d_p;
    }
    
    void upNode(Node* node) {
        if (node->d_n == d_tail) {
            return;
        }
        Node* target = node->d_n;
        isolateNode(node);
        //printList();
        while (target->d_c <= node->d_c) {
            target = target->d_n;
        }
        node->d_p = target->d_p;
        node->d_n = target;
        target->d_p->d_n = node;
        target->d_p = node;
    }
    
    void votePerson(int p) {
        Node* p_node = NULL;
        if (d_cast.find(p) == d_cast.end()) {
            p_node = new Node(p);
            d_cast[p] = p_node;
            insertNode(p_node);
        } else {
            p_node = d_cast[p];
        }
        ++(p_node->d_c);
        //printList();
        upNode(p_node);
    }
    */
};

/*
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
