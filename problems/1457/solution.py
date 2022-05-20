# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        self.count = 0
        self.get_paths(root)
        
        return self.count
        
    def get_paths(self, root):
        path = [] 
        self.get_paths_rec(root, path, 0)
    
    def get_paths_rec(self, root, path, pathLen): 
        if root is None: 
            return
    
        if(len(path) > pathLen):  
            path[pathLen] = root.val 
        else: 
            path.append(root.val) 

        pathLen = pathLen + 1

        if root.left is None and root.right is None: 
            if len(self.check_pp(path, pathLen)) <= 1:
                self.count += 1
        else: 
            self.get_paths_rec(root.left, path, pathLen) 
            self.get_paths_rec(root.right, path, pathLen)

    def check_pp(self, ints, len):
        return list([v for v in collections.Counter(ints[0 : len]).values() if v % 2])
        