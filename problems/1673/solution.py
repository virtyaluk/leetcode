class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        q, count = [], len(nums) - k
        
        for num in nums:
            while q and num < q[-1] and count > 0:
                q.pop()
                count -= 1
            
            q.append(num)
        
        return q[0:k]