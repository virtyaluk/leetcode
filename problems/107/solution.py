# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans = []
        
        if not root: return ans

        q = deque([root])
        
        while q:
            cur = []

            for _ in range(len(q)):
                node = q.popleft()
                
                if node:
                    cur.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            
            if cur:
                ans.append(cur)
        
        return ans[::-1]
                    