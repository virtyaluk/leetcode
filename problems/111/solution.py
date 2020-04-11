# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        q, depth = deque([root]), 0
        
        while q:
            depth += 1
            
            for _ in range(len(q)):
                cur = q.popleft()
    
                if not cur.left and not cur.right:
                    return depth

                if cur.left:
                    q.append(cur.left)

                if cur.right:
                    q.append(cur.right)
        
        return 0