# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        q, s = deque([(root, 0)]), 0
        
        while q:
            for _ in range(len(q)):
                node, cs = q.popleft()
                curs = cs * 10 + node.val
                
                if node.left:
                    q.append((node.left, curs))
                
                if node.right:
                    q.append((node.right, curs))
                
                if not node.left and not node.right:
                    s += curs
        
        return s