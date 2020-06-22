class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor, a, b = 0, 0, 0
        
        for num in nums:
            xor ^= num
        
        mask = xor & (-xor)
        
        for num in nums:
            if (mask & num) == 0:
                a ^= num
            else:
                b ^= num
        
        return [a, b]