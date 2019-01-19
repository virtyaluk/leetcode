class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hm = {}
        
        for i in range(len(nums)):
            compl = target - nums[i]
            
            if compl in hm:
                return [hm[compl], i]
            
            hm[nums[i]] = i