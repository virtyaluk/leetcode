class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        
        for i in range(n + 1):
            ans ^= i
        
        for num in nums:
            ans ^= num
        
        return ans