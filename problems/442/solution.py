class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        
        for num in nums:
            nums[abs(num) - 1] *= -1
        
        for num in nums:
            if nums[abs(num) - 1] > 0:
                ans.append(abs(num))
                nums[abs(num) - 1] *= -1
        
        return ans