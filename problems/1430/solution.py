# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        return self.helper(root, arr, len(arr), 0)
    
    def helper(self, node, arr, l, i):
        if not node:
            return l == 0
        
        if (i == l - 1) and (not node.left and not node.right) and (node.val == arr[i]):
            return True
        
        if (i < l) and (node.val == arr[i]):
            return (self.helper(node.left, arr, l, i + 1) or (self.helper(node.right, arr, l, i + 1)))