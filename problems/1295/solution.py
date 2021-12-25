from math import log10, floor

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        
        for n in nums:
            ans += 1 if not (floor(log10(n) + 1)) % 2 else 0
        
        return ans