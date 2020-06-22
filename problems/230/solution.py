# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        if not root:
            return 0
        
        count, curNode, kth_smallest = 0, root, 0
        
        while curNode:
            if not curNode.left:
                count += 1
                
                if count == k:
                    kth_smallest = curNode.val
                
                curNode = curNode.right
            else:
                prev = curNode.left
                
                while prev.right and prev.right != curNode:
                    prev = prev.right
                
                if not prev.right:
                    prev.right = curNode
                    curNode = curNode.left
                else:
                    prev.right = None
                    count += 1
                    
                    if count == k:
                        kth_smallest = curNode.val
                    
                    curNode = curNode.right
        
        return kth_smallest