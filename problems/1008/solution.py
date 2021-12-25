# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])
        
        for i in range(1, len(preorder)):
            self.append(root, preorder[i])
        
        return root
    
    def append(self, node, val):
        if val <= node.val:
            if node.left:
                self.append(node.left, val)
            else:
                node.left = TreeNode(val)
        else:
            if node.right:
                self.append(node.right, val)
            else:
                node.right = TreeNode(val)
            