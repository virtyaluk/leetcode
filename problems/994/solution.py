class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n, fresh, mins, q = len(grid), len(grid[0]), 0, -1, deque([])
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
        
        q.append((-1, -1))
        
        while q:
            i, j = q.popleft()
            
            if i == -1:
                mins += 1
                
                if q: q.append((-1, -1))
                
                continue
            
            for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ni, nj = i + x, j + y
                
                if m > ni >= 0 and n > nj >= 0 and grid[ni][nj] == 1:
                    grid[ni][nj] = 2
                    fresh -= 1

                    q.append((ni, nj))
        
        return mins if not fresh else -1