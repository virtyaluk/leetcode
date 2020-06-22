class Solution:
    def __init__(self):
        self.res = 0
        
    def dfs(self, node):
        if not node:
            return 0
        
        lv = self.dfs(node.left) + 1
        rv = self.dfs(node.right) + 1
        
        if node.left and node.left.val - node.val != 1:
            lv = 1
        
        if node.right and node.right.val - node.val != 1:
            rv = 1
        
        length = max(lv, rv)
        self.res = max(self.res, length)
        
        return length
            
    
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        
        return self.res