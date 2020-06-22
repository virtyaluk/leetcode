# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def helper(node):
            if not node:
                return '#,'
            
            return str(node.val) + ',' + helper(node.left) + helper(node.right)

        return helper(root)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        q = data.split(',')
        q.reverse()
        
        def helper():
            if not q:
                return None
            
            if q[-1] == '#':
                q.pop()
                return None
            
            node = TreeNode(int(q[-1]))
            q.pop()
            
            node.left = helper()
            node.right = helper()
            
            return node
        
        return helper()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))