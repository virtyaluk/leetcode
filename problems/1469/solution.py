# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        ans = []
        
        q = deque([(root, None)])
        
        while q:
            node, parent = q.popleft()
            
            if node.left: q.append((node.left, node))
            if node.right: q.append((node.right, node))
            
            if not parent or (parent.left and parent.right):
                continue
            
            ans.append(node.val)
        
        return ans