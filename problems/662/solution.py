# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        q, m = deque([root]), 0
        
        while q:
            while q and not q[0]:
                q.popleft()
            while q and not q[-1]:
                q.pop()
            
            qlen = len(q)
            m = max(m, qlen)
            
            for _ in range(qlen):
                node = q.popleft()
                
                if node:
                    q.append(node.left)
                    q.append(node.right)
                else:
                    q.append(None)
                    q.append(None)
                    
        
        return m