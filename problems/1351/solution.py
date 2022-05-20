class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        a = []
        
        for g in grid:
            a += g
        
        return len([n for n in a if n < 0])