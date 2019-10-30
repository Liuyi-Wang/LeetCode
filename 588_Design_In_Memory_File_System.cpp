static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

struct Dir {
    unordered_map<string, Dir*> d_d;    
    unordered_map<string, string> d_f;
};

class FileSystem {
public:
    FileSystem() {
        d_root = new Dir();
        mkdir("/");
    }
    
    vector<string> ls(string path) {
        vector<string> result;
        int last = path.find_last_of('/');
        bool isDir = true;
        Dir *root = NULL;
        if (0 == last) {
            /*
            cout << "ls=" << path << endl;
            for (unordered_map<string, string>::iterator it = d_root->d_f.begin(); it != d_root->d_f.end(); ++it) {
                cout << "?=" << it->first << endl;
            }*/
            root = d_root->d_d[""];
            if ("/" == path) {
                for (unordered_map<string, Dir*>::iterator it = root->d_d.begin(); it != root->d_d.end(); ++it) {
                    result.push_back(it->first);
                }
                for (unordered_map<string, string>::iterator it = root->d_f.begin(); it != root->d_f.end(); ++it) {
                    result.push_back(it->first);
                }
                sort(result.begin(), result.end());
                return result;
            } 
            isDir = root->d_f.find(path.substr(last+1, path.size()-1-last)) == root->d_f.end();
            //cout << "isD=" << isDir << endl;
            if (isDir) {
                root = root->d_d[path.substr(last+1, path.size()-1-last)];
                for (unordered_map<string, Dir*>::iterator it = root->d_d.begin(); it != root->d_d.end(); ++it) {
                    result.push_back(it->first);
                }
                for (unordered_map<string, string>::iterator it = root->d_f.begin(); it != root->d_f.end(); ++it) {
                    result.push_back(it->first);
                }
                sort(result.begin(), result.end());
                return result;
            } else {
                result.push_back(path.substr(last+1, path.size()-1-last));
                return result;
            }
            return result;
        }
        root = returnDir(path.substr(0, last));
        isDir = root->d_f.find(path.substr(last+1, path.size()-1-last)) == root->d_f.end();
        if (isDir) {
            root = root->d_d[path.substr(last+1, path.size()-1-last)];
            for (unordered_map<string, Dir*>::iterator it = root->d_d.begin(); it != root->d_d.end(); ++it) {
                result.push_back(it->first);
            }
            for (unordered_map<string, string>::iterator it = root->d_f.begin(); it != root->d_f.end(); ++it) {
                result.push_back(it->first);
            }
            sort(result.begin(), result.end());
        } else {
            result.push_back(path.substr(last+1, path.size()-1-last));
            return result;
            /*
            for (unordered_map<string, string>::iterator it = root->d_f.begin(); it != root->d_f.end(); ++it) {
                result.push_back(it->first);
            }
            sort(result.begin(), result.end());
            */
        }
        return result;
    }
    
    void mkdir(string path) {
        //cout << "mkdir=" << path << endl;
        returnDir(path);
    }
    
    void addContentToFile(string filePath, string content) {
        //cout << "addContentToFile=" << filePath << "," << content << endl;
        int last = filePath.find_last_of('/');
        if (0 == last) {
            Dir *dir = d_root->d_d[""];
            dir->d_f[filePath.substr(1, filePath.size()-1)] += content;
            return;
        }
        Dir *dir = returnDir(filePath.substr(0, last));
        dir->d_f[filePath.substr(last+1, filePath.size()-1-last)] += content;
    }
    
    string readContentFromFile(string filePath) {
        //cout << "readContentFromFile=" << filePath << endl;
        int last = filePath.find_last_of('/');
        if (0 == last) {
            Dir *dir = d_root->d_d[""];
            return dir->d_f[filePath.substr(1, filePath.size()-1)];
        }
        Dir *dir = returnDir(filePath.substr(0, last));
        return dir->d_f[filePath.substr(last+1, filePath.size()-1-last)];
    }
    
private:
    Dir* d_root;
    
    Dir* returnDir(const string& path) {
        Dir *root = d_root;
        stringstream ss(path);
        string dir;
        //cout << "pt=" << path << endl;
        while (getline(ss, dir, '/')) {
            //cout << "dir=" << dir << "|" << endl;
            if (root->d_d.find(dir) == root->d_d.end()) {
                root->d_d[dir] = new Dir();
            }
            root = root->d_d[dir];
        }
        return root;
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
