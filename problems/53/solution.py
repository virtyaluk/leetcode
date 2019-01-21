class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best_sum, cur_sum = nums[0], -1
        
        for v in nums:
            cur_sum = v if cur_sum < 0 else cur_sum + v
            best_sum = max(best_sum, cur_sum)
        
        return best_sum