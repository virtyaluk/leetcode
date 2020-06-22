class Solution:
    def countBits(self, num: int) -> List[int]:
        n = [0] * (num + 1)
        
        for i in range(1, num + 1):
            n[i] = n[i - 1] + 1 if i % 2 else n[i // 2]
        
        return n