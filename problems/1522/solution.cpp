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
    int diameter(Node* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    int helper(Node* root, int& ans) {
        if (not root) {
            return 0;
        }
        
        int firstMax = 0, secondMax = 0;
        
        for (Node *child: root->children) {
            int curLen = helper(child, ans);
            
            if (curLen > firstMax) {
                secondMax = firstMax;
                firstMax = curLen;
            } else if (curLen > secondMax) {
                secondMax = curLen;
            }
        }
        
        ans = max(ans, firstMax + secondMax);
        
        return 1 + firstMax;
    }
};