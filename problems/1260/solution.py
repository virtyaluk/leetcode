class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, cells, ans = len(grid), [], []
        
        for row in grid:
            cells += row
        
        k = k % len(cells)
        
        if not k:
            return grid
        
        cells = cells[-k:] + cells[:-k]
        step = len(cells) // m
        
        for i in range(0, len(cells), step):
            ans.append(cells[i:i+step])
        
        return ans