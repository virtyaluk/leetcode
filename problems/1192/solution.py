class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        ans, graph, visited, ids, low, idx = [], defaultdict(set), [False] * n, [0] * n, [0] * n, 0
        
        for [u, v] in connections:
            graph[u].add(v)
            graph[v].add(u)
        
        def dfs(at, prev):
            nonlocal idx
            
            visited[at] = True
            ids[at] = low[at] = idx
            idx += 1
            
            for to in graph[at]:
                if to == prev:
                    continue
                elif not visited[to]:
                    dfs(to, at)
                    low[at] = min(low[at], low[to])
                    
                    if ids[at] < low[to]:
                        ans.append([at, to])
                else:
                    low[at] = min(low[at], low[to])
        
        for i in range(n):
            if not visited[i]:
                dfs(i, -1)
        
        return ans