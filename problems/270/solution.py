# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        if not root:
            return 0
        
        min_diff, ans, q = float('inf'), 0, deque([root])
        
        while q:
            node = q.popleft()
            cur_diff = abs(target - node.val)
            
            if cur_diff < min_diff:
                min_diff = cur_diff
                ans = node.val
            
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        
        return ans
                