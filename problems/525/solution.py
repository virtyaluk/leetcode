class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        idx = defaultdict(list)
        idx[0] = [-1]
        cnt = 0
        
        for i in range(len(nums)):
            cnt += 1 if nums[i] else -1
            idx[cnt] += [i]
        
        return max(v[-1] - v[0] for v in idx.values())