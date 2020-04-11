# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.vals = []
        
        self.dfs(root)
        
    def dfs(self, node):
        if not node:
            return
        
        self.dfs(node.left)
        
        self.vals.append(node.val)
        
        self.dfs(node.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        return self.vals.pop(0)

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return bool(len(self.vals))


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()