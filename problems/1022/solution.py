# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        ans, q = 0, deque([(root, '')])
        
        while q:
            node, b = q.popleft()
            b += str(node.val)
            
            if not node.left and not node.right:
                ans += int(b, 2)
            
            if node.left: q.append((node.left, b))
            if node.right: q.append((node.right, b))
        
        return ans