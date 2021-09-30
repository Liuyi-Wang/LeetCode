static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        stringstream ss;
        se(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return de(ss);
    }
    
private:
    void se(Node* root, stringstream &ss) {
        if (NULL == root) {
            ss << "/ ";
            return;
        }
        ss << to_string(root->val) << " ";
        ss << to_string(root->children.size()) << " ";
        for (int i = 0; i < root->children.size(); ++i) {
            se(root->children[i], ss);
        }
    }
    
    Node* de(stringstream &ss) {
        string v;
        ss >> v;
        if ("/" == v) {
            return NULL;
        }
        string n;
        ss >> n;
        vector<Node*> children;
        for (int i = 0; i < atoi(n.c_str()); ++i) {
            children.push_back(de(ss));
        }
        return new Node(atoi(v.c_str()), children);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
