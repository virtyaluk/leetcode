class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()
        v, n = 0, 1
        
        if not str:
            return 0
        
        if str[0] in '+-':
            n = -1 if str[0] == '-' else 1
            str = str[1:]
        
        for ch in str:
            if not ch.isdigit():
                break
        
            v = v * 10 + int(ch)
        
        v *= n
        
        return min(max(v, -2**31), 2**31-1)
        