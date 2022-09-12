/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    Node(int v): val(v) {};
    Node(char o, Node* l, Node* r): op(o), left(l), right(r) {};
    virtual int evaluate() {
        if (op == 0) {
            return val;
        }
        
        int l = left->evaluate(), r = right->evaluate();
        
        if (op == '+') {
            return l + r;
        } else if (op == '-') {
            return l - r;
        } else if (op == '*') {
            return l * r;
        }
        
        return l / r;
    }
protected:
    Node *left = nullptr, *right = nullptr;
    int val = 0, op = 0;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node*> nodes;
        
        for (string token: postfix) {
            if (!isdigit(token[0])) {
                Node *right = nodes.back(), *left = nodes[nodes.size() - 2];
                nodes.resize(nodes.size() - 2);
                nodes.push_back(new Node(token[0], left, right));
            } else {
                nodes.push_back(new Node(stoi(token)));
            }
        }
        
        return nodes.back();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */