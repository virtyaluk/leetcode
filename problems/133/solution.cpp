/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> cache;

public:
    Node* cloneGraph(Node* node) {
        if (not node) {
            return nullptr;
        }
        
        if (cache.count(node)) {
            return cache[node];
        }
        
        Node *newNode = new Node(node->val);
        cache[node] = newNode;
        
        for (Node *child: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(child));
        }
        
        return newNode;
    }
};