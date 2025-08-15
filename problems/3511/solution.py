class Solution:
    def makeArrayPositive(self, nums: List[int]) -> int:
        ans, subSum = 0, sum(nums[:2])
        
        for i in range(2, len(nums)):
            curr_triplet = nums[i] + nums[i - 1] + nums[i - 2]
            subSum = min(subSum + nums[i], curr_triplet)
            
            if subSum <= 0:
                nums[i] = subSum = 10**18
                ans += 1

        return ans
