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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) {
            return new TreeNode(val);
        }
        
        if (val <= node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* node = nullptr;
        stringstream ss(data);
        string token;
        
        while(getline(ss, token, ',')) {
            node = insert(node, stoi(token));
        }
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;