class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        n1, n2, s, cur = len(num1) - 1, len(num2) - 1, "", False
        
        while n1 >= 0 or n2 >= 0:
            ns = 0

            if n1 >= 0:
                ns += (ord(num1[n1]) - ord('0'))
                n1 -= 1
            
            if n2 >= 0:
                ns += (ord(num2[n2]) - ord('0'))
                n2 -= 1
            
            if cur:
                ns += 1
                cur = False
            
            if ns > 9:
                cur = True
                ns -= 10
            
            s = str(ns) + s
        
        if cur:
            s = "1" + s
        
        return s