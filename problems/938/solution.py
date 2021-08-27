# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        val = 0
        
        if root:
            if root.val >= L and root.val <= R:
                val += root.val
        
            if root.left:
                val += self.rangeSumBST(root.left, L, R)
        
            if root.right:
                val += self.rangeSumBST(root.right, L, R)
        
        return val