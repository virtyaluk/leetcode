class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph, ans = defaultdict(list), []
        
        for u, v in tickets:
            graph[u].append(v)
        
        for v in graph:
            graph[v].sort(reverse=True)
        
        print(graph)
        
        def dfs(c):
            while graph[c]:
                dfs(graph[c].pop())
            
            ans.append(c)
        
        dfs('JFK')
        
        return ans[::-1]