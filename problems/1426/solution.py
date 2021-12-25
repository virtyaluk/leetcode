class Solution:
    def countElements(self, arr: List[int]) -> int:
        if not arr:
            return
        
        l = defaultdict(int)
        count = 0
        
        for num in arr:
            l[num] += 1
        
        for num in arr:
            if l[num + 1]:
                count += 1
        
        return count