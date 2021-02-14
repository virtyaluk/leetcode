# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        level_group_items = []       
        def level_items(root, level):
            if root:
                if len(level_group_items) == level:
                    level_group_items.append([])
                
                level_group_items[level].append(root.val)
                if root.left:
                    level_items(root.left, level+1)
                if root.right:
                    level_items(root.right, level+1)
            
        level_items(root, 0)
 
        levels_average = []
        for i in level_group_items:
            levels_average.append(sum(i)/len(i))
        
        return levels_average