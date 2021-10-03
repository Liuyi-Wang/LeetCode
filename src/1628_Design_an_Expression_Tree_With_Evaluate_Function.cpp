/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class Number: public Node {
public:
    Number(int number): d_number(number) {};
    int evaluate() const {
        return d_number;
    }
private:
    int d_number;
};

class Addition: public Node {
public:
    Addition(Node* l, Node* r): d_l(l), d_r(r) {};
    int evaluate() const {
        return d_l->evaluate()+d_r->evaluate();
    }
private:
    Node* d_l;
    Node* d_r;
};

class Substraction: public Node {
public:
    Substraction(Node* l, Node* r): d_l(l), d_r(r) {};
    int evaluate() const {
        return d_l->evaluate()-d_r->evaluate();
    }
private:
    Node* d_l;
    Node* d_r;
};

class Multiplication: public Node {
public:
    Multiplication(Node* l, Node* r): d_l(l), d_r(r) {};
    int evaluate() const {
        return d_l->evaluate()*d_r->evaluate();
    }
private:
    Node* d_l;
    Node* d_r;
};

class Division: public Node {
public:
    Division(Node* l, Node* r): d_l(l), d_r(r) {};
    int evaluate() const {
        return d_l->evaluate()/d_r->evaluate();
    }
private:
    Node* d_l;
    Node* d_r;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> stk;
        for (auto s:postfix) {
            if (s == "+") {
                Node* r = stk.top();
                stk.pop();
                Node* l = stk.top();
                stk.pop();
                Node* node = new Addition(l, r);
                stk.push(node);
            } else if (s == "-") {
                Node* r = stk.top();
                stk.pop();
                Node* l = stk.top();
                stk.pop();
                Node* node = new Substraction(l, r);
                stk.push(node);
            } else if (s == "*") {
                Node* r = stk.top();
                stk.pop();
                Node* l = stk.top();
                stk.pop();
                Node* node = new Multiplication(l, r);
                stk.push(node);
            } else if (s == "/") {
                Node* r = stk.top();
                stk.pop();
                Node* l = stk.top();
                stk.pop();
                Node* node = new Division(l, r);
                stk.push(node);
            } else {
                Node* node = new Number(stoi(s));
                stk.push(node);
            }
        }
        return stk.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
