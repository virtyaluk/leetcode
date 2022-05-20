class Solution:
    def maximum69Number (self, num: int) -> int:
        ns, i = str(num), 0
        
        while i < len(ns) and ns[i] != '6':
            i += 1
            
        if i >= len(ns):
            return num
        
        return int(ns[:i] + '9' + ns[i+1:])