class Solution {
private:
    bool dfs(int root, vector<int>& leftChild, vector<int>& rightChild, unordered_set<int>& nodes) {
        if (root == -1) {
            return true;
        }
        
        if (nodes.count(root)) {
            return false;
        }
        
        nodes.insert(root);
        
        return dfs(leftChild[root], leftChild, rightChild, nodes) and dfs(rightChild[root], leftChild, rightChild, nodes);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> childrens;
        int root;
        
        for (int i = 0; i < n; i++) {
            childrens.insert(leftChild[i]);
            childrens.insert(rightChild[i]);
        }
        
        childrens.erase(-1);
        
        if (size(childrens) != n - 1) {
            return false;
        }
        
        unordered_set<int> nodes;
        
        return dfs(root, leftChild, rightChild, nodes);
    }
};