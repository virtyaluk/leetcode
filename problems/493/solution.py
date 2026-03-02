from sortedcontainers import SortedList

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        l, ans = SortedList(), 0

        while nums:
            x = nums.pop()
            idx = l.bisect_left(x)
            ans += idx
            l.add(2 * x)
        
        return ans