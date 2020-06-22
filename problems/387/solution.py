class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = defaultdict(int)
        
        for ch in s:
            d[ch] += 1
        
        for idx, ch in enumerate(s):
            if d[ch] == 1:
                return idx
        
        return -1
            