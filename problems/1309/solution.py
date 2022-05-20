class Solution:
    def freqAlphabets(self, s: str) -> str:
        i, r = len(s) - 1, ''
        
        while i >= 0:
            if s[i] == '#':
                r = chr(int(s[i - 2:i]) + 96) + r
                i -= 2
            else:
                r = chr(int(s[i]) + 96) + r
            
            i -= 1
        
        return r