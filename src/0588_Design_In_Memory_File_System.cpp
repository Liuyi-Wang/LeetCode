class FileSystem {
    struct Node {
        set<string> d_files;
        map<string, Node*> d_dir;
        Node() {}
    };
    
    Node* root;
    unordered_map<string, string> path2content;
    
    vector<string> parsePath(const string& path) {
        vector<string> result;
        int i = 1;
        for (; i < path.size(); ++i) {
            int begin = i;
            while (i < path.size() && path[i] != '/') {
                ++i;
            }
            result.push_back(path.substr(begin, i-1-begin+1));
        }
        return result;
    }
    
    void createDir(const vector<string>& path) {
        Node* node = root;
        for (auto name:path) {
            if (node->d_dir.find(name) == node->d_dir.end()) {
                node->d_dir[name] = new Node();
            }
            node = node->d_dir[name];
        }
    }
    
    vector<string> lsAll(const vector<string>& path) {
        Node* node = root;
        for (auto name:path) {
            node = node->d_dir[name];
        }
        set<string> s = node->d_files;
        for (auto it:node->d_dir) {
            s.insert(it.first);
        }
        vector<string> result;
        for (auto name:s) {
            result.push_back(name);
        }
        return result;
    }
    
    void createFile(const vector<string>& path) {
        Node* node = root;
        for (int i = 0; i < path.size()-1; ++i) {
            if (node->d_dir.find(path[i]) == node->d_dir.end()) {
                node->d_dir[path[i]] = new Node();
            }
            node = node->d_dir[path[i]];
        }
        node->d_files.insert(path.back());
    }
public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        if (path2content.find(path) != path2content.end()) {
            vector<string> v = parsePath(path);
            return {v.back()};
        }
        return lsAll(parsePath(path));
    }
    
    void mkdir(string path) {
        createDir(parsePath(path));
    }
    
    void addContentToFile(string filePath, string content) {
        if (path2content.find(filePath) == path2content.end()) {
            createFile(parsePath(filePath));
        }
        path2content[filePath] += content;
    }
    
    string readContentFromFile(string filePath) {
        return path2content[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
