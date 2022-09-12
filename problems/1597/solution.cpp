/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        vector<Node*> ans;
        
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '(') {
                int j = i + 1;
                
                for (int bal = 1; bal > 0; j++) {
                    bal += s[j] == ')' ? -1 : s[j] == '(' ? 1 : 0;
                }
                
                ans.push_back(expTree(s.substr(i + 1, j - i - 2)));
                
                i = j - 1;
            } else {
                ans.push_back(new Node(s[i]));
            }
        }
        
        return op(op(ans, '*', '/'), '+', '-').front();
    }
    
    vector<Node*> op(const vector<Node*>& nodes, char op1, char op2) {
        vector<Node*> ans;
        
        for (auto it = begin(nodes); it != end(nodes); it++) {
            Node *node = *it;
            
            if (not node->left and (node->val == op1 or node->val == op2)) {
                node->left = ans.back();
                node->right = *next(it);
                ans.back() = node;
                it++;
            } else {
                ans.push_back(node);
            }
        }
        
        return ans;
    }
};