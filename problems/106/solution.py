# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder and not postorder:
            return None
        
        idx = inorder.index(postorder[-1])
        # print('in', inorder[:idx], postorder[:idx])
        # print('post', inorder[idx + 1:], postorder[idx:-1])
        
        leftNode = self.buildTree(inorder[:idx], postorder[:idx])
        rightNode = self.buildTree(inorder[idx + 1:], postorder[idx:-1])
        
        return TreeNode(postorder[-1], leftNode, rightNode)