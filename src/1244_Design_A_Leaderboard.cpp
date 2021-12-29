class Leaderboard {
public:
    struct Node {
        int d_score;
        Node* next;
        Node* prev;
        Node(int score): d_score(score) {
            next = NULL;
            prev = NULL;
        }
    };
    
    Leaderboard() {
        begin = new Node(INT_MIN);
        end = new Node(INT_MAX);
        begin->next = end;
        end->prev = begin;
    }
    
    void addScore(int playerId, int score) {
        //cout << playerId << "," << score << endl;
        if (id2node.find(playerId) != id2node.end()) {
            Node* node = id2node[playerId];
            remove(node);
            node->d_score += score;
            insert(node);
        } else {
            Node* node = new Node(score);
            insert(node);
            id2node[playerId] = node;
        }
    }
    
    int top(int K) {
        int sum = 0;
        Node* node = end->prev;
        //print();
        for (int i = 0; i < K; ++i) {
            sum += node->d_score;
            node = node->prev;
        }
        return sum;
    }
    
    void reset(int playerId) {
        Node* node = id2node[playerId];
        remove(node);
        id2node.erase(playerId);
    }
    
private:
    unordered_map<int, Node*> id2node;
    Node* begin;
    Node* end;
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(Node* node) {
        Node* it = begin;
        while (it->d_score <= node->d_score) {
            it = it->next;
        }
        Node* prev = it->prev;
        it->prev = node;
        node->next = it;
        node->prev = prev;
        prev->next = node;
        //print();
    }
    
    void print() {
        Node* it = begin->next;
        while (it) {
            cout << it->d_score << ",";
            it = it->next;
        }
        cout << endl;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
