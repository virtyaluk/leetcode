class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        num_good_nodes = 0
        
        # Use collections.deque for efficient popping
        queue = deque([(root, float("-inf"))])
        while queue:
            node, max_so_far = queue.popleft()
            if max_so_far <= node.val:
                num_good_nodes += 1
            if node.right:
                queue.append((node.right, max(node.val, max_so_far)))
            if node.left:
                queue.append((node.left, max(node.val, max_so_far)))
        
        return num_good_nodes