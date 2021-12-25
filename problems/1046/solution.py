from heapq import heapify, heappush, heappop

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i in range(len(stones)):
            stones[i] *= -1
        
        while len(stones) > 1:
            heapify(stones)
            
            s1 = heappop(stones)
            s2 = heappop(stones)
            
            if s1 != s2:
                stones.append(s1 - s2)
        
        return stones[0] * -1 if stones else 0