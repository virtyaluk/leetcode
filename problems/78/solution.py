class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [[nums[j] for j in range(len(nums)) if i & (1 << j)] for i in range(1 << len(nums))]
