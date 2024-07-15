class Solution:
    def numSteps(self, s: str) -> int:
        ans, n = 0, int(s, 2)
        
        while n != 1:
            ans += 1
            if not n % 2:
                n //= 2
            else:
                n += 1
        
        return ans