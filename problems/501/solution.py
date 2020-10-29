import sys

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        freq, q, ans, most_freq = defaultdict(int), deque([root]), [], -1
        
        while q:
            node = q.popleft()
            freq[node.val] += 1
            
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
                
        for k, f in sorted(freq.items(), key=lambda x: -x[1]):
            if most_freq == -1:
                most_freq = f
            
            if most_freq != f:
                break
            
            ans.append(k)

        return ans