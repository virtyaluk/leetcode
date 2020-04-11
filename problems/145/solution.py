# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        
        q = [root]
        
        while q:
            node = q.pop()
            
            if node:
                ans.insert(0, node.val)
                q.append(node.left)
                q.append(node.right)
        
        return ans