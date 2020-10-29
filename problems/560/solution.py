class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        c, s, am = 0, 0, defaultdict(int)
        am[0] += 1
        
        for n in nums:
            s += n
            c += am[s - k]
            am[s] += 1
        
        return c