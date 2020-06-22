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
private:
    string serializeHelper(TreeNode *root) {
        if (not root) {
            return "#,";
        }
        
        return to_string(root->val) + "," + serializeHelper(root->left) + serializeHelper(root->right);
    }
    
    TreeNode* deserialize(queue<string>& q) {
        if (empty(q)) {
            return nullptr;
        }
        
        if (q.front() == "#") {
            q.pop();
            
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(stoi(q.front()));
        q.pop();
        
        node->left = deserialize(q);
        node->right = deserialize(q);
        
        return node;
    }
    
    TreeNode *deserializeHelper(string data) {
        queue<string> q;
        istringstream iss(data);
        string token;
        
        while (getline(iss, token, ',')) {
            q.push(token);
        }
        
        return deserialize(q);
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serializeHelper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));