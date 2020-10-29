class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxOnes = curOnes = 0
        
        for i in range(len(nums)):
            if nums[i]:
                curOnes = curOnes + 1 if i > 0 and nums[i -1] else 1

            maxOnes = max(maxOnes, curOnes)
        
        return maxOnes