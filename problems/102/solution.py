# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        ans, q = [], deque([root])
        
        while q:
            level = []
            
            for _ in range(len(q)):
                node = q.popleft()
                
                level.append(node.val)
                
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            
            ans.append(level)
        
        return ans
