class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        if len(nums) <= 1:
            return nums
        
        ln = 0
        
        for i in range(len(nums)):
            if nums[i]:
                # tmp = nums[i]
                # nums[i] = 0
                # nums[ln] = tmp
                nums[i], nums[ln] = 0, nums[i]
                # nums.insert(ln, nums.pop(i))
                ln += 1
                
                
        