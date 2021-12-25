class Solution:
    def isArmstrong(self, N: int) -> bool:
        nlen, n, ans = int(math.log10(N) + 1), N, 0
        
        while n:
            ans += (n % 10) ** nlen
            n //= 10
        
        return ans == N