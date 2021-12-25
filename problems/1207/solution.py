class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d, s = defaultdict(int), set()
        
        for num in arr:
            d[num] += 1
        
        for v in d.values():
            if v in s:
                return False
            
            s.add(v)
        
        return True