# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        if not root1 or not root2:
            return False
        
        diff, q = set(), deque([root1])
        
        while q:
            node = q.popleft()
            
            diff.add(target - node.val)
            
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        
        q.append(root2)
        
        while q:
            node = q.popleft()
            
            if node.val in diff:
                return True
            
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        
        return False