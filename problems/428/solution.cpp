/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
private:
    string serializeHelper(const Node *node) {
        if (not node) {
            return "";
        }
        
        string ans = "[" + to_string(node->val) + "](";
        
        for (const Node* child: node->children) {
            ans += serializeHelper(child);
        }
        
        ans.push_back(')');
        
        return ans;
    }
    
    Node* deserializeHelper(string& s, int& idx) {
        if (empty(s) or idx >= size(s) or s[idx] != '[') {
            idx++;
            return nullptr;
        }
        
        Node *node = new Node(0);
        idx++;
        
        while (idx < size(s) and isdigit(s[idx])) {
            node->val = node->val * 10 + (s[idx++] - '0');
        }
        
        idx++;
        idx++;
        
        while (idx < size(s) and s[idx] != ')') {
            Node *child = deserializeHelper(s, idx);
            node->children.push_back(child);
            idx++;
        }
        
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        return serializeHelper(root);;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int i = 0;
        
        return deserializeHelper(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
/*

[1]([3]([5](),[6]()),[2](),[4]())

*/