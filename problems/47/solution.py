class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans, comb, counter, n = [], [], defaultdict(int), len(nums)
        
        for num in nums:
            counter[num] += 1
        
        def backtrack():
            if len(comb) == n:
                ans.append(comb.copy())
                return
            
            for num, count in counter.items():
                if count == 0:
                    continue
                
                counter[num] -= 1
                comb.append(num)
                
                backtrack()
                
                comb.pop()
                counter[num] += 1
        
        backtrack()
        
        return ans