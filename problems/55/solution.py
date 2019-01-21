class Solution:
    def canJump(self, nums: List[int]) -> bool:
        li = len(nums) - 1
        
        for i in reversed(range(len(nums) - 1)):
            if i + nums[i] >= li:
                li = i
        
        return li == 0