# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if not root:
            return False
        
        dif, q = set(), deque([root])
        
        while q:
            node = q.popleft()
            
            if node.val in dif:
                return True
            
            dif.add(k - node.val)
            
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        
        return False