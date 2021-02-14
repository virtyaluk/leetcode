class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        q = (len(B) - 1) // len(A) + 1
        
        for i in range(2):
            if B in A * (q + i):
                return q + i
        
        return -1