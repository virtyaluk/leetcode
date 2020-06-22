# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        
        q = [root]
        
        while q:
            cur = q.pop()
            
            cur.left, cur.right = cur.right, cur.left
            
            if cur.left:
                q.append(cur.left)
            
            if cur.right:
                q.append(cur.right)
        
        return root