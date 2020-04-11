class Solution:
    def findMin(self, nums: List[int]) -> int:
        m = nums[0]
        
        for num in nums:
            if num < m:
                m = num
        
        return m