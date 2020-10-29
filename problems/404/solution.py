# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        ans, q = 0, deque([(root, False)])
        
        while q:
            node, is_left = q.popleft()
            
            if is_left and not node.left and not node.right:
                ans += node.val
            
            if node.left: q.append((node.left, True))
            if node.right: q.append((node.right, False))
        
        return ans