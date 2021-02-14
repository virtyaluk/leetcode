class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        ans, m, n = 0, len(grid), len(grid[0])
        
        def checkArea(x, y):
            size, q = 0, deque([(x, y)])
            
            while q:
                i, j = q.popleft()
                
                if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                    continue
                
                size += 1
                grid[i][j] = 0
                
                q.append((i + 1, j))
                q.append((i, j + 1))
                q.append((i - 1, j))
                q.append((i, j - 1))
            
            return size
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans = max(ans, checkArea(i, j))
        
        return ans