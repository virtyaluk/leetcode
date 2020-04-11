class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not len(grid):
            return 0
        
        islands = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    islands += 1
                    
                    self.dfs(grid, i, j)
        
        return islands
    
    
    def dfs(self, grid: List[List[str]], i: int, j: int):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[i]) or grid[i][j] != '1':
            return
        
        grid[i][j] = '0'
        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)