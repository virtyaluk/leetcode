/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return nullptr;
        }
        
        return build(grid, 0, grid.size() - 1, 0, grid.back().size() - 1);
    }
    
    Node* build(const vector<vector<int>>& g, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart == rowEnd) {
            return new Node(g[rowStart][colStart], true);
        }
        
        int len = rowEnd - rowStart + 1;
        int rowMid = rowStart + len / 2,
            colMid = colStart + len / 2;
        
        Node *topLeft = build(g, rowStart, rowMid - 1, colStart, colMid - 1),
            *topRight = build(g, rowStart, rowMid - 1, colMid, colEnd),
            *bottomLeft = build(g, rowMid, rowEnd, colStart, colMid - 1),
            *bottomRight = build(g, rowMid, rowEnd, colMid, colEnd);
        int val = topLeft->val;
        vector<Node*> children = {topLeft, topRight, bottomLeft, bottomRight};
        
        for (Node *child: children) {
            if (not child->isLeaf or val != child->val) {
                return new Node(val, false, topLeft, topRight, bottomLeft, bottomRight);
            }
        }
        
        return new Node(val, true);
    }
};