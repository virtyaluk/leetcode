class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        m, sum = 2**31, 0
        
        for n in nums:
            sum += n
            m = min(m, sum)
        
        return 1 if m >= 1 else abs(m - 1)