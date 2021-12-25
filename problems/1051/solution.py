class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        ans, hs = 0, sorted(heights)
        
        for i in range(len(hs)):
            if heights[i] - hs[i]:
                ans += 1
        
        return ans