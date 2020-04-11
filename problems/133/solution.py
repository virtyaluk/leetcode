"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = {}
        
        def dfs(node):
            if not node:
                return None
            
            if node in visited:
                return visited[node]
            
            cloned = Node(node.val, [])
            visited[node] = cloned
            
            for neighbor in node.neighbors:
                cloned.neighbors.append(dfs(neighbor))
            
            return cloned
        
        return dfs(node)