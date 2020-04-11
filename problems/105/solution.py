# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(i):
            if not i:
                return None
            
            node = TreeNode(preorder.pop(0))
            idx = i.index(node.val)
            node.left = helper(i[:idx])
            node.right = helper(i[idx + 1:])
            
            return node
        
        return helper(inorder)