# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        
        ans, q = 0, deque([(root, [])])
        
        while q:
            node, vals = q.popleft()
            nvals = vals + [0]
            
            for i in range(len(nvals)):
                nvals[i] += node.val
                
                if nvals[i] == sum:
                    ans += 1
            
            if node.left: q.append((node.left, nvals))
            if node.right: q.append((node.right, nvals))
        
        return ans