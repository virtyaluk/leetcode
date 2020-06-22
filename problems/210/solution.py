class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph, ans, colors, cycle = defaultdict(list), [], [0] * numCourses, False
        
        for u, v in prerequisites:
            graph[v].append(u)
        
        def dfs(i):
            nonlocal cycle

            if cycle:
                return
            
            colors[i] = 1
            
            if i in graph:
                for j in graph[i]:
                    if colors[j] == 1:
                        cycle = True
                        return
                    elif colors[j] == 0:
                        dfs(j)
            
            colors[i] = 2
            ans.append(i)
        
        for i in range(numCourses):
            if colors[i] == 0:
                dfs(i)
        
        return [] if cycle else ans[::-1]