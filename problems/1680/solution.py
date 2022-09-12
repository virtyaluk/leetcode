class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans, size = 0, 0
        
        for i in range(1, n + 1):    
            if i & (i - 1) == 0:
                size += 1
            ans = ((ans << size) | i) % 1000000007
        
        return ans