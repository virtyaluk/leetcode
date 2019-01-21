class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def bs(lo, hi):
            if lo > hi:
                return -1
            
            mid = (lo + hi) // 2
            
            if nums[mid] == target:
                return mid
            elif (nums[lo] <= target and target < nums[mid]) or (nums[mid] < nums[hi] and not (nums[mid] < target and target <= nums[hi])):
                return bs(lo, mid - 1)
            else:
                return bs(mid + 1, hi)
        
        return bs(0, len(nums) - 1)