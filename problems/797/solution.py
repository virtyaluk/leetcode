class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans, q, target = [], deque([[0]]), len(graph) - 1
        
        while q:
            cur_path = q.popleft()
            
            if cur_path[-1] == target:
                ans.append(cur_path)
                continue

            for child in graph[cur_path[-1]]:
                q.append(cur_path + [child])
        
        return ans