# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        cur, lh, rh = root, 0, 0
        
        while cur:
            lh += 1
            cur = cur.left
        
        cur = root
        
        while cur:
            rh += 1
            cur = cur.right
        
        
        if lh == rh:
            return 2**lh - 1
        
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)