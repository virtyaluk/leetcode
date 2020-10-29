class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        
        first, second, third = -sys.maxsize - 1, -sys.maxsize - 1, -sys.maxsize - 1
        
        for n in set(nums):
            if n > first:
                third, second, first = second, first, n
            elif n < first and n > second:
                third, second = second, n
            elif n < second and n > third:
                third = n
        
        if third == -sys.maxsize - 1:
            return first
        
        return third