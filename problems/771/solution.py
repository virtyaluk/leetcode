class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        jewels, ans = set(J), 0
        
        for s in S:
            if s in jewels:
                ans += 1
        
        return ans
        