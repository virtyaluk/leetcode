# n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        ans, stops, adj, dists, q = float('inf'), 0, [[0 for _ in range(n)] for _ in range(n)], {}, deque([src])
        
        for f, t, p in flights:
            adj[f][t] = p
        
        dists[(src, 0)] = 0
        
        while q and stops <= k:
            qSize = len(q)
            
            for _ in range(qSize):
                node = q.popleft()
                
                for next in range(n):
                    if adj[node][next] > 0:
                        du = dists.get((node, stops), float('inf'))
                        dv = dists.get((next, stops + 1), float('inf'))
                        wuv = adj[node][next]
                        
                        if stops == k and next != dst:
                            continue
                        
                        if du + wuv < dv:
                            dists[next, stops + 1] = du + wuv
                            q.append(next)
                            
                            if next == dst:
                                ans = min(ans, du + wuv)
                                
            stops += 1
        
        return -1 if ans == float('inf') else ans