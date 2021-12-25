class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        ans, g, indegree = 0, [[] for _ in range(n)], [0] * n
        
        for [u, v] in relations:
            g[u - 1].append(v - 1)
            indegree[v - 1] += 1
        
        q = [i for i in range(n) if not indegree[i]]
        
        while q:
            nq = []
            ans += 1
            for node in q:
                for next in g[node]:
                    indegree[next] -= 1
                    
                    if not indegree[next]:
                        nq.append(next)
            
            q = nq
        
        if len([i for i in range(n) if indegree[i]]):
            return -1
        
        return ans