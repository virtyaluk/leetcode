class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 0:
            return True
        
        graph, visited = defaultdict(list), [0] * numCourses
        
        def dfs(c):
            visited[c] = 1
            
            for nc in graph[c]:
                if visited[nc] or not dfs(nc):
                    return False
            
            visited[c] = 0

            return True
        
        for u, v in prerequisites:
            graph[v].append(u)
        
        for i in range(numCourses):
            if not dfs(i):
                return False
        
        return True