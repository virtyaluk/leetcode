/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (not root) {
            return root;
        }
        
        Node *cur = root, *dummy = new Node(), *prev = dummy;
        
        while (cur) {
            if (cur->left) {
                Node *rightmost = cur->left;
                
                while (rightmost->right and rightmost != prev) {
                    rightmost = rightmost->right;
                }
                
                if (rightmost == prev) {
                    prev->right = cur;
                    cur->left = prev;

                    prev = cur;
                    cur = cur->right;
                } else {
                    rightmost->right = cur;
                    cur = cur->left;
                }
            } else {
                prev->right = cur;
                cur->left = prev;
                
                prev = cur;
                cur = cur->right;
            }
        }
        
        Node *head = dummy->right, *tail = prev;
        head->left = tail;
        tail->right = head;
        
        return head;
    }
    
    Node* treeToDoublyList2(Node* root) {
        if (not root) {
            return root;
        }
        
        Node *head = nullptr, *prev = nullptr;
        stack<Node*> st;
        
        while (not empty(st) or root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            // cout << root->val << endl;
            if (not head) {
                head = root;
            }
            
            root->left = prev;
            
            if (prev) {
                prev->right = root;
            }
            
            prev = root;
            root = root->right;
        }
        
        head->left = prev;
        prev->right = head;
        
        return head;
    }
    
    Node* treeToDoublyList1(Node* root) {
        if (not root) {
            return root;
        }
        
        stack<Node*> st;
        vector<Node*> nodes;
        
        while (not empty(st) or root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                
                nodes.push_back(root);
                
                root = root->right;
            }
        }
        
        for (int i = 1; i < size(nodes); i++) {
            nodes[i - 1]->right = nodes[i];
            nodes[i]->left = nodes[i - 1];
        }
        
        nodes[0]->left = nodes.back();
        nodes.back()->right = nodes[0];
        
        return nodes[0];
    }
};