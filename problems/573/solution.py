class Solution:
    def dist(self, a, b):
        [x0, y0], [x1, y1] = a, b
        
        return abs(x0 - x1) + abs(y0 - y1)
    
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        ans, [ta, tb], maxSavedDist = 0, tree, -20000
        
        for nut in nuts:
            ans += 2 * self.dist(nut, tree)
            maxSavedDist = max(maxSavedDist, self.dist(nut, tree) - self.dist(nut, squirrel))
        
        return ans - maxSavedDist