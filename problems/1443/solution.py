class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        m = {}
        
        for f, t in edges:
            if f not in m:
                m[f] = set()
            
            m[f].add(t)
        
        def go(vertex):
            depth = 0
            
            if hasApple[vertex] and vertex:
                depth += 1
            
            if vertex in m:
                childsDepth = 0
                
                for child in m[vertex]:
                    childsDepth += go(child)
                
                if not depth and childsDepth and vertex:
                    depth += 1
                
                depth += childsDepth
            
            return depth
        
        return go(0) * 2
            