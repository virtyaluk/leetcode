class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        nums = set()
        
        for n in arr:
            if n not in nums:
                nums.add(n*2)
                nums.add(n/2)
            else:
                return True
        
        return False
        