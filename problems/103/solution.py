# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        ans = []
        reverse = False
        q = deque([root])

        while q:
            qlen, newQ = len(q), deque()
            ans.append([])

            while qlen:
                qlen -= 1
                node = q.popleft()
                ans[-1].append(node.val)
                
                if node.left:
                    newQ.append(node.left)
                
                if node.right:
                    newQ.append(node.right)
            
            q = newQ
            
            if reverse:
                ans[-1] = ans[-1][::-1]
            
            reverse = not reverse
        
        return ans
