class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        for x in range(m):
            for y in range(n):
                if not x and not y:
                    continue
                
                left = grid[x - 1][y] if x else 2**31
                top = grid[x][y - 1] if y else 2**31
                grid[x][y] += min(left, top)
        
        return grid[m - 1][n - 1]