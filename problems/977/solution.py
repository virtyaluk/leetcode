class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        l, r, pos, res = 0, len(A) - 1, len(A) - 1, [0] * len(A)
        
        while l <= r:
            if A[r] > abs(A[l]):
                res[pos] = A[r]**2
                r -= 1
            else:
                res[pos] = A[l]**2
                l += 1
            
            pos -= 1
        
        return res