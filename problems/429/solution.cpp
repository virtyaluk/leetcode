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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (not root) {
            return {};
        }
        
        vector<vector<int>> ans;
        queue<Node*> q;
        
        q.push(root);
        
        while (not empty(q)) {
            ans.push_back({});
            
            for (int i = size(q) - 1; i >= 0; i--) {
                Node *node = q.front();
                q.pop();
                
                ans.back().push_back(node->val);
                
                for (Node *next: node->children) {
                    q.push(next);
                }
            }
        }
        
        return ans;
    }
};