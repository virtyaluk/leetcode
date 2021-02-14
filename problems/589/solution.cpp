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
    vector<int> preorder(Node* root) {
        if (not root) {
            return {};
        }
        
        vector<int> ans;
        stack<Node*> st;
        
        st.push(root);
        
        while (not st.empty()) {
            Node *cur = st.top();
            st.pop();

            ans.push_back(cur->val);

            for (auto it = rbegin(cur->children); it != rend(cur->children); it++) {
                st.push(*it);
            }
        }
        
        return ans;
    }
    
    vector<int> preorder1(Node* root) {
        vector<int> ans;
        
        dfs(root, ans);
        
        return ans;
    }
    
    void dfs(Node* node, vector<int>& ans) {
        if (not node) {
            return;
        }
        
        ans.push_back(node->val);
        
        for (Node *child: node->children) {
            dfs(child, ans);
        }
    }
};