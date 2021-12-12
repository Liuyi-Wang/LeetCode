class SORTracker {
    int i;
    struct cmpSmaller {
        inline bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) {
            if (p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        }
    };
    struct cmpGreater {
        inline bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) {
            if (p1.second == p2.second) {
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmpSmaller> maxH;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmpGreater> minH;
public:
    SORTracker() {
        i = 0;
    }
    
    void add(string name, int score) {
        if (maxH.empty()) {
            minH.push({name, score});
        } else if (score > maxH.top().second || (score == maxH.top().second && name < maxH.top().first)) {
            minH.push({name, score});
        } else {
            maxH.push({name, score});
        }
    }
    
    string get() {
        while (!minH.empty() && minH.size() > i+1) {
            maxH.push(minH.top());
            minH.pop();
        }
        string result = minH.top().first;
        ++i;
        if (!maxH.empty()) {
            minH.push(maxH.top());
            maxH.pop();
        }
        return result;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
