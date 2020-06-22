class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n < 2:
            return range(n)
        
        g, rem = defaultdict(set), n
        
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        
        leaves = [i for i in range(n) if len(g[i]) == 1]
        
        while rem > 2:
            rem -= len(leaves)
            newLeaves = []
            
            for leaf in leaves:
                for neib in g[leaf]:
                    g[neib].remove(leaf)
                    
                    if len(g[neib]) == 1:
                        newLeaves.append(neib)
            
            leaves = newLeaves
        
        return leaves