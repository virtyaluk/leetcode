# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        node, _ = self.find(root)
        
        return node
    
    def find(self, node):
        if not node:
            return None, 0
        
        lnode, lh = self.find(node.left)
        rnode, rh = self.find(node.right)
        
        if lh == rh:
            return node, lh + 1
        elif lh > rh:
            return lnode, lh + 1
        
        return rnode, rh + 1