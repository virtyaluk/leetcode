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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) {
            return NULL;
        }
        
        TreeNode* rootNode = new TreeNode(root->val);
        queue<pair<TreeNode*, Node*>> q;

        q.push(make_pair(rootNode, root));
        
        while (!q.empty()) {
            auto [parent, cur] = q.front();
            q.pop();
            TreeNode *prevBNode = NULL, *headBNode = NULL;
            
            for (Node* child: cur->children) {
                TreeNode* newBNode = new TreeNode(child->val);
                
                if (prevBNode) {
                    prevBNode->right = newBNode;
                } else {
                    headBNode = newBNode;
                }
                
                prevBNode = newBNode;
                q.push(make_pair(newBNode, child));
            }
            
            parent->left = headBNode;
        }
        
        return rootNode;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        
        Node* rootNode = new Node(root->val);
        queue<pair<Node*, TreeNode*>> q;
        
        q.push(make_pair(rootNode, root));
        
        while (!q.empty()) {
            auto [parent, cur] = q.front();
            q.pop();
            TreeNode* firstChild = cur->left;
            TreeNode* sibling = firstChild;
            
            while (sibling) {
                Node* newNode = new Node(sibling->val);
                
                parent->children.push_back(newNode);
                q.push(make_pair(newNode, sibling));
                sibling = sibling->right;
            }
        }
        
        return rootNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));