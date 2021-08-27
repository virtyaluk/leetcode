class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        
        l = 0
        r = len(A) - 1
        
        while l + 1 < len(A) and A[l] < A[l + 1]:
            l += 1
        
        if not l or l == len(A) - 1:
            return False
        
        while r - 1 >= 0 and A[r] < A[r - 1]:
            r -= 1
        
        return l == r