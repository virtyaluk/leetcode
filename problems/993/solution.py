# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root:
            return False
        
        xEsists, xDepth, xParent = self.findDepthAndParent(root, x, 0, None)
        yExists, yDepth, yParent = self.findDepthAndParent(root, y, 0, None)
        
        print(xDepth, xParent)
        print(yDepth, yParent)
        
        if not (xEsists and yExists):
            return False
        
        return xDepth == yDepth and xParent != yParent
    
    def findDepthAndParent(self, node, val, k, parent):
        if not node:
            return (False, None, None)
        
        k += 1
        
        if node.val == val:
            return (True, k, parent)
        
        found, newK, newParent = self.findDepthAndParent(node.left, val, k, node)
        
        if found:
            return (found, newK, newParent)
        
        return self.findDepthAndParent(node.right, val, k, node)