# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        ans = ""
        
        def traverse(node):
            if not node:
                return
        
            nonlocal ans
            
            traverse(node.left)
            traverse(node.right)
            
            ans += str(node.val) + ','
        
        traverse(root)
        
        return ans
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        def buildTree(lower, upper):
            if not nums or nums[-1] < lower or nums[-1] > upper:
                return None
            
            val = nums.pop()
            node = TreeNode(val)
            node.right = buildTree(val, upper)
            node.left = buildTree(lower, val)
            
            return node
    
        nums = [int(x) for x in data.split(',') if x]
    
        return buildTree(float('-inf'), float('inf'))

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans